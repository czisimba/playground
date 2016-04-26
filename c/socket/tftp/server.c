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
    int pckt_len = 0;
    int transmit_len = 0;

    transmit_len = recvfrom(sock, buff, sizeof(buff), 0, NULL, NULL);
    if (*(unsigned short *)buff == OPTCODE_GET_REQUEST) {
        // send get response msg
        init_msg_t *msg = (init_msg_t *)buff;
        printf("client get request msg,file name:%s\n", msg->filename);
        struct stat file_stat;
        if (stat(msg->filename, &file_stat))         //得到文件大小
        {
            printf("file is empty!\n");
            return -1;
        }
        msg->len = (int)(file_stat.st_size);
        printf("file len:%u\n", msg->len);
        msg->opcode = OPTCODE_GET_RESPONSE;
        sendto(sock, msg, transmit_len, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));

        // send file
        int fd;
        fd = open(msg->filename, O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(-1);
        }
        int nread = 0;
        char *data = buff + sizeof(datablock_t);
        while ((nread = read(fd, data, 1400)) > 0) {
            sendto(sock, buff, nread + sizeof(datablock_t), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
            usleep(10 * 1000);
        }
        close(fd);
    }

    exit(0);
}
