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

void tftpd_process(int recv_len);
enum {
   TFTPD_STATE_ZERO = 0,
   TFTPD_STATE_RRQ_RECV,
   TFTPD_STATE_RRQ_DATA_SEND,
   TFTPD_STATE_WRQ_DATA_RECV,
};
int tftpd_state = TFTPD_STATE_ZERO;

struct sockaddr_in clientaddr, local_addr;
int             sock;
/*
fd_set rds;
struct timeval timeout;
*/
#define BUFF_SIZE 15000
char buff[BUFF_SIZE];//in buff
datablock_t *block_recv = (datablock_t *)buff;
char data[BUFF_SIZE];//out buff
datablock_t *block_send = (datablock_t *)data;
int main(int argc, char **argv)
{
    int recv_len = 0;

	clientaddr.sin_family = AF_INET;
	clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientaddr.sin_port = htons(CLIENT_TFTP_PORT);

	if ((sock = socket(AF_INET,SOCK_DGRAM,0)) == -1) {
        perror("socket");
        exit(1);
    }

    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(SERVPORT);
    if (bind(sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind"); 
        exit(1);
    }


    while (1) {
        recv_len = recvfrom(sock, buff, sizeof(buff), 0, NULL, NULL);
        printf("recv code:%u\n", *(unsigned short *)buff);
        if (*(unsigned short *)buff >= RRQ && *(unsigned short *)buff <= ACK) {
            tftpd_process(recv_len);
        }
    }

    exit(0);
}

unsigned short blocknum = 0;// send file
int nread = 0, transmited_len = 0, filelen = 0;
void send_file_data(int fd, int retransmit)
{
    char *data_file = data + sizeof(datablock_t);

    if (retransmit) {
        sendto(sock, data, nread + sizeof(datablock_t), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
        printf("retransmit send file data block:%d len:%d\n", block_send->blocknum, nread);
        return;
    }
    if ((nread = read(fd, data_file, 1400)) > 0) {
        // send file data
        block_send->opcode = DATA;
        transmited_len += nread;
        block_send->blocknum = blocknum++;
        sendto(sock, data, nread + sizeof(datablock_t), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
        printf("send file data block:%d len:%d, transmited_len:%d, file_len:%d\n", block_send->blocknum, nread, transmited_len, filelen);
    }
}

void send_ack()
{
    block_send->opcode = ACK;
    block_send->blocknum = block_recv->blocknum;
    sendto(sock, data, sizeof(datablock_t), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
}

void tftpd_process(int recv_len)
{
    char filepath[MAX_FILENAME_LEN];
    static int fd;
    static int max_block_num = -1;// recv file

    switch (tftpd_state) {
    case TFTPD_STATE_ZERO:
        if (*(unsigned short *)buff == RRQ) {// recv RRQ
            // check if file valid
            blocknum = 0;
            transmited_len = 0;
            init_msg_t *msg = (init_msg_t *)buff;
            sprintf(filepath, "/tftpboot/%s", msg->filename);
            printf("client get request msg,file name:%s,filepath:%s\n", msg->filename, filepath);
            struct stat file_stat;
            if (stat(filepath, &file_stat))         //得到文件大小
            {
                // send err msg
                msg->opcode = ERROR;
                msg->error_code = ERROR_CODE_FILE_NOTFOUND;
                sendto(sock, msg, recv_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
                printf("file is empty!\n");
                return;
            }
            msg->len = filelen = (int)(file_stat.st_size);
            // send RRQ response
            fd = open(filepath, O_RDONLY);
            if (fd < 0) {
                perror("open");
                return;
            }
            printf("file len:%u\n", msg->len);
            sendto(sock, msg, recv_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
            tftpd_state = TFTPD_STATE_RRQ_RECV;
        } else if (*(unsigned short *)buff == WRQ) {
            // check if file valid
            init_msg_t *msg = (init_msg_t *)buff;
            sprintf(filepath, "/tftpboot/%s", msg->filename);
            printf("client put request msg,file name:%s,filepath:%s\n", msg->filename, filepath);
            mode_t new_umask = 0666;  
            fd = open(filepath, O_RDWR |O_APPEND | O_CREAT | O_TRUNC);
            if (fd < 0) {
                perror("open");
                exit(-1);
            }
            chmod(filepath, new_umask);
            max_block_num = -1;
            transmited_len = 0;
            filelen = msg->len;
            // send WRQ response msg
            printf("file len:%u\n", msg->len);
            sendto(sock, msg, recv_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
            tftpd_state = TFTPD_STATE_WRQ_DATA_RECV;
        }

        break;
    case TFTPD_STATE_RRQ_RECV:
        if (*(unsigned short *)buff != RRQ) {
            tftpd_state = TFTPD_STATE_ZERO;
            return;
        } else {
            send_file_data(fd, 0);
            tftpd_state = TFTPD_STATE_RRQ_DATA_SEND;
        }
        break;
    case TFTPD_STATE_RRQ_DATA_SEND:
        if (*(unsigned short *)buff == ACK) {// ACK
            if (transmited_len == filelen) {//send finished
                tftpd_state = TFTPD_STATE_ZERO;
                close(fd);
                return;
            }
            // send file
            if (block_recv->blocknum == blocknum - 1) {
                send_file_data(fd, 0);
            } else {// retransmit
                send_file_data(fd, 1);
            }
        }
        break;
    case TFTPD_STATE_WRQ_DATA_RECV:
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
            tftpd_state = TFTPD_STATE_ZERO;
            close(fd);
            return;
        }
        break;
        default:
        break;
    }

    return;
}
