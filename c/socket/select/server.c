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
#define LISTEN_PORT 11010

int main()
{
    int listen_sock = 0, app_sock = 0;
    struct sockaddr_in hostaddr, clientaddr;
    struct timeval timeout;
    fd_set rds;
    char recvbuf[RECV_BUF_SIZE] = {0};
    int retlen = 0, leftlen = 0;
    char *ptr = NULL;

    memset((void *)&hostaddr, 0, sizeof(hostaddr));
    memset((void *)&clientaddr, 0, sizeof(clientaddr));
    hostaddr.sin_family = AF_INET;
    hostaddr.sin_port = htons(LISTEN_PORT);
    hostaddr.sin_addr.s_addr = htonl(INADDR_ANY);//auto get system ip address
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_sock < 0) {
        perror("%s:%d, create socket failed");
        exit(1);
    }
    if(bind(listen_sock, (struct sockaddr *)&hostaddr, sizeof(hostaddr)) < 0)
    {
        perror("%s:%d, bind socket failed");
        exit(1);
    }
    if(listen(listen_sock, MAX_LISTEN_NUM) < 0)
    {
        syslog(LOG_ERR, "%s:%d, listen failed", __FILE__, __LINE__);
        exit(1);
    }
    while(1)
    {
        FD_ZERO(&rds);
        FD_SET(listen_sock, &rds);
        timeout.tv_sec  = 5;
        timeout.tv_usec = 0;

        int ret = select(listen_sock+1, &rds, NULL, NULL, &timeout);
        if ( ret == 0 ) {
            printf("Time Expired\n");
            continue;
        } else if ( ret < 0) {
            printf("Socket Error\n");
            continue;
        } 
        printf("Socket select num:%d\n", ret);
        if (FD_ISSET(listen_sock, &rds)) {
            app_sock = accept(listen_sock, NULL, NULL);
            if(app_sock < 0)
            {
                printf("%s:%d, accept failed", __FILE__, __LINE__);
                exit(1);
            }
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
            printf("receive data is : %s\n", recvbuf);
            close(app_sock);
        }
    }
    close(listen_sock);

    return 0;
}
