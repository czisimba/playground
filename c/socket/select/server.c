#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>

#define MAX_LISTEN_NUM 5
#define SEND_BUF_SIZE 100
#define RECV_BUF_SIZE 100
#define LISTEN_PORT_START 11010
#define MAX_LISTEN_SOCKET 100

int main()
{
    int sock[MAX_LISTEN_SOCKET], max_sock_fd = 0;
    struct sockaddr_in hostaddr, clientaddr;
    struct timeval timeout;
    fd_set rds;
    char recvbuf[RECV_BUF_SIZE] = {0};
    int retlen = 0, leftlen = 0;
    char *ptr = NULL;
    int i;
    short listen_port = LISTEN_PORT_START;

    FD_ZERO(&rds);
    memset((void *)&clientaddr, 0, sizeof(clientaddr));
    for (i = 0;i < MAX_LISTEN_SOCKET;i++) {
        memset((void *)&hostaddr, 0, sizeof(hostaddr));
        hostaddr.sin_family = AF_INET;
        hostaddr.sin_port = htons(listen_port++);
        hostaddr.sin_addr.s_addr = htonl(INADDR_ANY);//auto get system ip address
        sock[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (sock[i] < 0) {
            perror("%s:%d, create socket failed");
            exit(1);
        }
        if (bind(sock[i], (struct sockaddr *)&hostaddr, sizeof(hostaddr)) < 0)
        {
            perror("%s:%d, bind socket failed");
            exit(1);
        }
        if (listen(sock[i], MAX_LISTEN_NUM) < 0)
        {
            syslog(LOG_ERR, "%s:%d, listen failed", __FILE__, __LINE__);
            exit(1);
        }
        FD_SET(sock[i], &rds);
        printf("i:%d sock:%d\n", i, sock[i]);
        if (sock[i] > max_sock_fd)
            max_sock_fd = sock[i];
        printf("max_sock_fd:%d\n", max_sock_fd);
    }

    while(1)
    {
        timeout.tv_sec  = 5;
        timeout.tv_usec = 0;

        int ret = select(max_sock_fd+1, &rds, NULL, NULL, NULL);
        if ( ret == 0 ) {
            printf("Time Expired\n");
            continue;
        } else if ( ret < 0) {
            printf("Socket Error\n");
            continue;
        } 
        printf("Socket select num:%d\n", ret);
        for (i = 0;i < MAX_LISTEN_SOCKET;i++) {
            if (FD_ISSET(sock[i], &rds)) {
                int app_sock = accept(sock[i], NULL, NULL);
                if(app_sock < 0)
                {
                    printf("%s:%d, accept failed", __FILE__, __LINE__);
                    exit(1);
                }
                printf("accept socket fd: %d\n", sock[i]);
                //receive data
                ptr = recvbuf;
                leftlen = RECV_BUF_SIZE -1;
                {
                    retlen = recv(app_sock, ptr, leftlen, 0) ;
                    if(retlen < 0)
                    {
                        if(errno == EINTR)
                            retlen = 0;
                        else
                            exit(1);
                    }
                    leftlen -= retlen;
                    ptr += retlen;
                }
                printf("i is %d\n,receive data is : %s\n", i, recvbuf);
                close(app_sock);
            }
        }
    }
    for (i = 0;i < MAX_LISTEN_SOCKET;i++)
        close(sock[i]);

    return 0;
}
