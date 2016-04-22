
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>

#define SEND_BUF_SIZE 100
int main()
{
    char sendbuf[SEND_BUF_SIZE] = {0};
    char addr_s[20] = "192.168.1.1";
    struct in_addr addr;
    struct sockaddr_in clientaddr;
    memset((void *)&clientaddr, 0, sizeof(clientaddr));

    sprintf(sendbuf, "welcome %s:%d here!/n", (char *)inet_ntoa(clientaddr.sin_addr), clientaddr.sin_port);
    inet_aton(addr_s, &addr);
    printf("addr_s:%s, addr:0x%x\n", addr_s, addr);

    return 0;
}
