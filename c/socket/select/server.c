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

#define MAX_LISTEN_NUM 1000
#define MAXLINE 1500
#define SERVER_PORT 5000
int main()
{
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char buf[MAXLINE];
    socklen_t clilen;
    struct sockaddr_in cliaddr, serveraddr;
    int connet_num = 0;

    // init
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(-1);
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SERVER_PORT);
    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        exit(-1);
    }
    if (listen(listenfd, MAX_LISTEN_NUM)) {
        perror("listen");
        exit(-1);
    }

    maxfd = listenfd;
    maxi = -1;
    for (i = 0;i < FD_SETSIZE;i++)
        client[i] = -1;
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    // process
    for (;;) {
        rset = allset;
        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (nready < 0)
            continue;

        if (FD_ISSET(listenfd, &rset)) {
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
            connet_num++;
            printf("now connect num:%d\n", connet_num);
            for (i = 0;i < FD_SETSIZE;i++) {
                if (client[i] < 0) {
                    client[i] = connfd;
                    break;
                }
            }
            if (i == FD_SETSIZE) {
                perror("too much client");
                break;
            }
            FD_SET(connfd, &allset);
            printf("put %d in allset\n", connfd);
            if (connfd > maxfd)
                maxfd = connfd;
            if (i > maxi)
                maxi = i;
            if (--nready <= 0)
                continue;
        }

        for (i = 0;i <= maxi;i++) {
            if ( (sockfd = client[i]) < 0)
                continue;
            printf("fd %d exist\n", sockfd);
            if (FD_ISSET(sockfd, &rset)) {
                printf("fd %d is set\n", sockfd);
                if ((n = recv(sockfd, buf, MAXLINE, MSG_DONTWAIT)) == 0) {
                    close(sockfd);
                    printf("close fd:[%d]\n", sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                } else {
                    printf("recv data:[%s]\n", buf);
                    send(sockfd, buf, MAXLINE, MSG_DONTWAIT);
                }

                if (--nready <= 0)
                    break;
            }
        }
    }

    exit(0);
}
