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
#include "common.h"


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

int main(int argc, char **argv)
{
	int             sock;
	struct sockaddr_in serveraddr, local_addr;

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

#define BUFF_SIZE 15000
    char buff[BUFF_SIZE];
    int pckt_len = 0;
    int recv_len = 0;
    if (transmit_mode == TRANSMIT_MODE_GET) {
        // send get request msg
        init_msg_t *msg = (init_msg_t *)buff;
        msg->opcode = OPTCODE_GET_REQUEST;
        msg->len = 0;
        strcpy(msg->filename, filename);
        pckt_len = sizeof(init_msg_t) + strlen(msg->filename) + 1;
        sendto(sock, msg, pckt_len, 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        printf("send len:%u\n", pckt_len);
        printf("downloading...\n");

        // recv get response msg
        recv_len = recvfrom(sock, msg, sizeof(buff), 0, NULL, NULL);
        if (recv_len < 8 || msg->opcode != OPTCODE_GET_RESPONSE) {
            printf("file not found...\n");
            exit(1);
        }
        // recv file
        int fd;
        mode_t new_umask = 0666;  
        fd = open(filename, O_RDWR |O_APPEND | O_CREAT | O_TRUNC);
        if (fd < 0) {
            perror("open");
            exit(-1);
        }
        chmod(filename, new_umask);
        int leftlen;
        leftlen = pckt_len = msg->len;
        datablock_t *block = (datablock_t *)buff;
        while (leftlen) {
            // get && write file data
            int data_len;
            recv_len = recvfrom(sock, block, sizeof(buff), 0, NULL, NULL);
            data_len = recv_len - sizeof(datablock_t);
            printf("recv file data len:%u\n" ,data_len);
            write(fd, buff + sizeof(datablock_t), data_len);
            leftlen -= data_len;
            // send ack
            block->opcode = OPTCODE_DATA_ACK;
            sendto(sock, block, sizeof(datablock_t), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
            printf("send ack,block num:%d\n" ,block->blocknum);
        }
        close(fd);
    } else {// put
        // send put request msg
        char remote_filename[MAX_FILENAME_LEN];
        init_msg_t *msg = (init_msg_t *)buff;
        struct stat file_stat;
        if (stat(filename, &file_stat))         //得到文件大小
        {
            perror("stat");
            exit(1);
        }
        msg->opcode = OPTCODE_PUT_REQUEST;
        msg->len = (int)(file_stat.st_size);
        strcpy(remote_filename, filename);
        strcpy(msg->filename, tail(remote_filename));
        pckt_len = sizeof(init_msg_t) + strlen(msg->filename) + 1;
        sendto(sock, msg, pckt_len, 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        printf("send filename:%s, len:%u\n", filename, pckt_len);
        printf("uploading...\n");

        // recv get response msg
        recv_len = recvfrom(sock, msg, sizeof(buff), 0, NULL, NULL);
        if (recv_len < 8 || msg->opcode != OPTCODE_PUT_RESPONSE) {
            printf("can't upload...\n");
            exit(1);
        }
        // send file
        int fd;
        fd = open(filename, O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(-1);
        }
        int nread = 0;
        unsigned short blocknum = 0;
        int try_cnt = 5;
        datablock_t *block = (datablock_t *)buff;
        char *data = buff + sizeof(datablock_t);
        while ((nread = read(fd, data, 1400)) > 0) {
            while (1) {
                // send file data
                block->opcode = OPTCODE_DATABLOCK;
                block->blocknum = blocknum++;
                sendto(sock, buff, nread + sizeof(datablock_t), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
                printf("send file data len:%d\n", nread);
                // recv ack
                recvfrom(sock, block, sizeof(buff), 0, NULL, NULL);
                printf("recv ack,block num:%d\n" ,block->blocknum);
                if (block->opcode != OPTCODE_DATA_ACK || block->blocknum != blocknum - 1) {
                    blocknum--;
                    printf("block num not match,retransmit\n");
                    if (--try_cnt == 0)
                        break;
                    continue;
                }
                break;
            }
            if (try_cnt == 0)
                break;
        }
        close(fd);
    }

    exit(0);
}
