#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>

#define SEND_BUF_SIZE 100
#define SERVER_PORT_START 5000
#define MAX_CONNECT_SOCKET 10000
int main()
{
    int sock_fd = 0;
    char sendbuf[SEND_BUF_SIZE] = {0};
    int retlen = 0;
    int leftlen = 0;
    char *ptr = NULL;
    struct sockaddr_in ser_addr;
    short server_port = SERVER_PORT_START;
    int i;

    memset(&ser_addr, 0, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", (struct in_addr *)&ser_addr.sin_addr);
    ser_addr.sin_port = htons(server_port);
    for (i = 0;i < MAX_CONNECT_SOCKET;i++) {
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(sock_fd < 0)
        {
            printf("%s:%d, create socket failed\n", __FILE__, __LINE__);
            exit(1);
        }
        if(connect(sock_fd, (struct sockaddr *)&ser_addr, sizeof(ser_addr)) < 0)
        {
            printf("%s:%d, connect socket failed\n", __FILE__, __LINE__);
            exit(1);
        }
        printf("port %d connect\n", server_port);
        //send data
        sprintf(sendbuf, "hello i am client %d", sock_fd);
        leftlen = strlen(sendbuf) + 1;
        ptr = sendbuf;
        while(leftlen)
        {
            retlen = send(sock_fd, ptr, leftlen, 0);
            printf("send data:[%s]\n", ptr);
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
        close(sock_fd);
    }

    return 0;

}
