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

    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(CLIENT_PORT);
    if (bind(sockfd, (struct sockaddr *)&client_addr,sizeof(client_addr)) == -1) {
        syslog(LOG_ERR, "%s:%d, bind socket failed,errno:%d", __FILE__, __LINE__, errno); 
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    char message[MAX_MESSAGE_LEN];
    int msg_len,cnt = 0;
    while (cnt < 100)
    {
        sprintf(message, "heartbeat %d", cnt);
        msg_len = strlen(message);
        sendto(sockfd, message, msg_len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        debug("send heartbeat %s:%d,No:%d\r\n", (char *)inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port), cnt);
        cnt++;
    }
    sleep(30);

    close(sockfd);

    exit(0);
}
