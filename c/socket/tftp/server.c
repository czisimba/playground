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

static char filepath[MAX_FILENAME_LEN];
int main(int argc, char **argv)
{
	int             sock;
	struct sockaddr_in clientaddr, local_addr;


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

#define BUFF_SIZE 15000
    char buff[BUFF_SIZE];
    int transmit_len = 0;

    while (1) {
        transmit_len = recvfrom(sock, buff, sizeof(buff), 0, NULL, NULL);
        if (*(unsigned short *)buff == OPTCODE_GET_REQUEST) {
            init_msg_t *msg = (init_msg_t *)buff;
            sprintf(filepath, "/tftpboot/%s", msg->filename);
            printf("client get request msg,file name:%s,filepath:%s\n", msg->filename, filepath);
            struct stat file_stat;
            if (stat(filepath, &file_stat))         //得到文件大小
            {
                // send err msg
                msg->opcode = OPTCODE_ERROR;
                msg->error_code = ERROR_CODE_FILE_NOTFOUND;
                sendto(sock, msg, transmit_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
                printf("file is empty!\n");
                continue;
            }
            // send get response msg
            msg->len = (int)(file_stat.st_size);
            printf("file len:%u\n", msg->len);
            msg->opcode = OPTCODE_GET_RESPONSE;
            sendto(sock, msg, transmit_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));

            // send file
            int fd;
            fd = open(filepath, O_RDONLY);
            if (fd < 0) {
                perror("open");
                continue;
            }
            int nread = 0;
            unsigned short blocknum = 0;
            int try_cnt = 5;
            char *data = buff + sizeof(datablock_t);
            datablock_t *block = (datablock_t *)buff;
            while ((nread = read(fd, data, 1400)) > 0) {
                while (1) {
                    // send file data
                    block->opcode = OPTCODE_DATABLOCK;
                    block->blocknum = blocknum++;
                    sendto(sock, buff, nread + sizeof(datablock_t), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
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
        } else if (*(unsigned short *)buff == OPTCODE_PUT_REQUEST) {
            // ...
            init_msg_t *msg = (init_msg_t *)buff;
            sprintf(filepath, "/tftpboot/%s", msg->filename);
            printf("client put request msg,file name:%s,filepath:%s\n", msg->filename, filepath);
            /*
            struct stat file_stat;
            if (stat(filepath, &file_stat))         //得到文件大小
            {
                // send err msg
                msg->opcode = OPTCODE_ERROR;
                msg->error_code = ERROR_CODE_FILE_NOTFOUND;
                sendto(sock, msg, transmit_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
                printf("file is empty!\n");
                continue;
            }
            */
            // send get response msg
            printf("file len:%u\n", msg->len);
            msg->opcode = OPTCODE_PUT_RESPONSE;
            sendto(sock, msg, transmit_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
            
            // recv file
            int fd;
            mode_t new_umask = 0666;  
            fd = open(filepath, O_RDWR |O_APPEND | O_CREAT | O_TRUNC);
            if (fd < 0) {
                perror("open");
                exit(-1);
            }
            chmod(filepath, new_umask);
            int leftlen;
            leftlen = msg->len;
            datablock_t *block = (datablock_t *)buff;
            while (leftlen) {
                // get && write file data
                int data_len;
                int recv_len = 0;
                recv_len = recvfrom(sock, block, sizeof(buff), 0, NULL, NULL);
                data_len = recv_len - sizeof(datablock_t);
                printf("recv file data len:%u\n" ,data_len);
                write(fd, buff + sizeof(datablock_t), data_len);
                leftlen -= data_len;
                // send ack
                block->opcode = OPTCODE_DATA_ACK;
                sendto(sock, block, sizeof(datablock_t), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
                printf("send ack,block num:%d\n" ,block->blocknum);
            }
            close(fd);
        }
    }

    exit(0);
}
