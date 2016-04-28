#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include "tftp.h"

void tftp_start();
void tftp_process(int recv_len);
enum {
   TFTP_STATE_ZERO = 0,
   TFTP_STATE_RRQ_SEND,
   TFTP_STATE_RRQ_DATA_RECV,
   TFTP_STATE_WRQ_SEND,
   TFTP_STATE_WRQ_DATA_SEND,
};

int tftp_state = TFTP_STATE_ZERO;

#define TRANSMIT_MODE_GET 1
#define TRANSMIT_MODE_PUT 2
static int transmit_mode;

static char filename[MAX_FILENAME_LEN];

int opt_parse(int argc, char **argv)
{
    int c;

    struct option opts[] = {
        {"get", required_argument,NULL,'g'},
        {"put", required_argument,NULL,'p'},
        {"help", no_argument,NULL,'h'},
    };

    opterr = 0;

    while((c=getopt_long(argc,argv,"g:p:h::",opts,NULL)) != -1)
    {
        switch(c)
        {
            case 'g':
                transmit_mode = TRANSMIT_MODE_GET;
                strcpy(filename, optarg);
                break;
            case 'p':
                transmit_mode = TRANSMIT_MODE_PUT;
                strcpy(filename, optarg);
                break;
            case 'h':
            case '?':
            default:
                printf("Usage : \n"
                        "-g get: disable tty \n"
                        "-p put: disable adk\n"
                        "-h usage: show usage\n"
                      );
                return -1;
                break;
        }
    }

    printf("%s %s\n", transmit_mode == TRANSMIT_MODE_GET ? "get" : "put", filename);

    return 0;
}

char *tail(char *filename)
{
    char *s;

    while (*filename) {
        s = strrchr(filename, '/');
        if (s == NULL)
            break;
        if (s[1])
            return (s + 1);
        *s = '\0';
    }
    return (filename);
}

int             sock;
struct sockaddr_in serveraddr, local_addr;

#define BUFF_SIZE 15000
char buff[BUFF_SIZE];//in buff
datablock_t *block_recv = (datablock_t *)buff;
char data[BUFF_SIZE];//out buff
datablock_t *block_send = (datablock_t *)data;
fd_set rds;
struct timeval timeout;
int main(int argc, char **argv)
{
    int recv_len = 0;

    if (opt_parse(argc, argv) == -1)
        exit(-1);

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_port = htons(SERVPORT);

	if ((sock = socket(AF_INET,SOCK_DGRAM,0)) == -1) {
        perror("socket");
        exit(1);
    }

    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(CLIENT_TFTP_PORT);
    if (bind(sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind"); 
        exit(1);
    }

    tftp_start();
    while (1) {
        recv_len = recvfrom(sock, buff, sizeof(buff), 0, NULL, NULL);
        if (*(unsigned short *)buff >= RRQ && *(unsigned short *)buff <= ACK) {
            tftp_process(recv_len);
        }
    }

    exit(0);
}

int fd;
int max_block_num = -1;// recv file
int nread = 0, transmited_len = 0, filelen = 0;
unsigned short blocknum = 0;
void tftp_start()
{
    int msg_len = 0;
    blocknum = 0;
    transmited_len = 0;

    if (transmit_mode == TRANSMIT_MODE_GET) {
        // send RRQ
        max_block_num = -1;
        init_msg_t *msg = (init_msg_t *)buff;
        msg->opcode = RRQ;
        msg->len = 0;
        strcpy(msg->filename, filename);
        msg_len = sizeof(init_msg_t) + strlen(msg->filename) + 1;
        sendto(sock, msg, msg_len, 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        printf("send len:%u\n", msg_len);
        printf("downloading...\n");

        mode_t new_umask = 0666;  
        fd = open(filename, O_RDWR |O_APPEND | O_CREAT | O_TRUNC);
        if (fd < 0) {
            perror("open");
            exit(-1);
        }
        chmod(filename, new_umask);
        tftp_state = TFTP_STATE_RRQ_SEND;
    } else {// put
        // send put request msg
        char remote_filename[MAX_FILENAME_LEN];
        init_msg_t *msg = (init_msg_t *)buff;
        struct stat file_stat;
        if (stat(filename, &file_stat))
        {
            perror("stat");
            exit(1);
        }
        msg->opcode = WRQ;
        msg->len = (int)(file_stat.st_size);
        strcpy(remote_filename, filename);
        strcpy(msg->filename, tail(remote_filename));
        msg_len = sizeof(init_msg_t) + strlen(msg->filename) + 1;
        sendto(sock, msg, msg_len, 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        printf("send filename:%s, len:%u\n", filename, msg_len);
        printf("uploading...\n");
        fd = open(filename, O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(-1);
        }
        tftp_state = TFTP_STATE_WRQ_SEND;
    }
}

void send_file_data(int fd, int retransmit)
{
    char *data_file = data + sizeof(datablock_t);

    if (retransmit) {
        sendto(sock, data, nread + sizeof(datablock_t), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        printf("retransmit send file data block:%d len:%d\n", block_send->blocknum, nread);
        return;
    }
    if ((nread = read(fd, data_file, 1400)) > 0) {
        // send file data
        block_send->opcode = DATA;
        block_send->blocknum = blocknum++;
        printf("send file data block:%d len:%d, transmited_len:%d, file_len:%d\n", blocknum, nread, transmited_len, filelen);
        transmited_len += nread;
        sendto(sock, data, nread + sizeof(datablock_t), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    }
}

void send_ack()
{
    block_send->opcode = ACK;
    block_send->blocknum = block_recv->blocknum;
    sendto(sock, data, sizeof(datablock_t), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
}

void tftp_stat_err()
{
    tftp_state = TFTP_STATE_ZERO;
    close(fd);
}

void tftp_process(int recv_len)
{
    switch (tftp_state) {
    case TFTP_STATE_RRQ_SEND:
        if (*(unsigned short *)buff != RRQ) {// send rrq again
            tftp_stat_err();
            return;
        }
        init_msg_t *msg = (init_msg_t *)buff;
        filelen = msg->len;//init filelen here
        sendto(sock, buff, recv_len, 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        tftp_state = TFTP_STATE_RRQ_DATA_RECV;
        break;
    case TFTP_STATE_RRQ_DATA_RECV:
        if (*(unsigned short *)buff != DATA) {// send rrq again
            tftp_stat_err();
            return;
        }
        if (block_recv->blocknum > max_block_num) {
            max_block_num = block_recv->blocknum;
            int data_len = recv_len - sizeof(datablock_t);
            printf("recv file data len:%u\n" ,data_len);
            write(fd, buff + sizeof(datablock_t), data_len);
            transmited_len += data_len;
        }
        send_ack();
        printf("send ack blocknum:%u,recv_len:%d, transmited_len:%d, filelen:%d\n", block_send->blocknum, recv_len, transmited_len, filelen);
        if (transmited_len == filelen) {//recv finished
            tftp_stat_err();
            return;
        }
        break;
    case TFTP_STATE_WRQ_SEND:
        if (*(unsigned short *)buff != WRQ) {
            tftp_stat_err();
            return;
        } else {
            send_file_data(fd, 0);
            tftp_state = TFTP_STATE_WRQ_DATA_SEND;
        }
        break;
    case TFTP_STATE_WRQ_DATA_SEND:
        if (*(unsigned short *)buff != ACK || transmited_len == filelen) {
            tftp_stat_err();
            return;
        }
        // send file
        if (block_recv->blocknum == blocknum - 1) {
            send_file_data(fd, 0);
        } else {// retransmit
            send_file_data(fd, 1);
        }
        break;
    default://ignore TFTP_STATE_ZERO
        break;
    }
}
