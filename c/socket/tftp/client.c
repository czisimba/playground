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
            perror("get response msg");
            exit(1);
        }
        // recv file
        int fd;
        fd = open("./tmp", O_RDWR |O_APPEND | O_CREAT | O_TRUNC);
        if (fd < 0) {
            perror("open");
            exit(-1);
        }
        int leftlen;
        leftlen = pckt_len = msg->len;
        while (leftlen) {
            int data_len;
            recv_len = recvfrom(sock, buff, sizeof(buff), 0, NULL, NULL);
            data_len = recv_len - sizeof(datablock_t);
            //printf("recv file data len:%u\n" ,data_len);
            write(fd, buff + sizeof(datablock_t), data_len);
            leftlen -= data_len;
        }
        close(fd);
    } else {// put
        // ...
    }

    exit(0);
}
