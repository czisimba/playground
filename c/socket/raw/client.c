#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
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

#define MAX_MESSAGE_LEN 256
#define LISTEN_PORT 9000
//#define __DEBUG__

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
    int server_sockfd, server_len, client_len;
    struct sockaddr_in server_address, client_address;
    char message[MAX_MESSAGE_LEN];

    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);//UDP
    if (server_sockfd == -1) {
        syslog(LOG_ERR, "%s:%d, create socket failed,errno:%d",__FILE__, __LINE__, errno); 
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(LISTEN_PORT);
    server_len = sizeof(server_address);

    /*
    if (bind(server_sockfd, (struct sockaddr *)&server_address,server_len) == -1) {
        syslog(LOG_ERR, "%s:%d, bind socket failed,errno:%d", __FILE__, __LINE__, errno); 
        exit(1);
    }
    */

    while (1) {
        bzero(message, sizeof(message));
        strcpy(message, "hello,i am chengzhi\n");
        sendto(server_sockfd, message, sizeof(message), 0, (struct sockaddr *)&server_address, server_len);
        
        //recvfrom(server_sockfd, message, sizeof(message), 0, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
        //debug("receive data from %s:%d message len:%lu\n", (char *)inet_ntoa(client_address.sin_addr), client_address.sin_port, strlen(message));
        sleep(1);
                
    }
    
    close(server_sockfd);
    exit(0);
}
