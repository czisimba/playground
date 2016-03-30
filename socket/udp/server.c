#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <error.h>
#include <syslog.h>
#include <pthread.h>

#define MAX_MESSAGE_LEN 256
#define CLIENT_PORT 7088
#define SERVER_PORT 7089

#define __DEBUG__ 
#ifdef __DEBUG__
#include <stdarg.h>
void debug(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}
#else
void debug(const char *fmt, ...)
{
}
#endif

 
int main()
{
    int sockfd;
    struct sockaddr_in client_addr, server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);//UDP
    if (sockfd == -1) {
        syslog(LOG_ERR, "%s:%d, create socket failed,errno:%d",__FILE__, __LINE__, errno); 
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr)) == -1) {
        syslog(LOG_ERR, "%s:%d, bind socket failed,errno:%d", __FILE__, __LINE__, errno); 
        exit(1);
    }

    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(CLIENT_PORT);

    char message[MAX_MESSAGE_LEN];
    int msg_len;
    sleep(10);// wait for some packet in buffer
    while (1)
    {
		msg_len = recvfrom(sockfd, message, MAX_MESSAGE_LEN, 0, NULL, NULL);
        debug("recv msg:%s\r\n", message);
    }

    close(sockfd);

    exit(0);
}
