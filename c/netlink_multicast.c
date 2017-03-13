#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/socket.h>
#include <errno.h>

struct msg_struct
{
    unsigned video_width;
    unsigned video_height;
    unsigned video_freq;
    unsigned video_interlaced;
    unsigned video_hdcp;
    unsigned audio_freq;
};

#define NETLINK_IT6604E 21
#define MAX_PAYLOAD 1024 // maximum payload size
int sock_fd;
struct sockaddr_nl src_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
struct msghdr msg;

void init_netlink()
{
    // Create a socket
    sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_IT6604E);
    if(sock_fd == -1)
    {
        printf("error getting socket: %s", strerror(errno));
        return;
    }
    // To prepare binding
    memset(&msg,0,sizeof(msg));
    memset(&src_addr, 0, sizeof(src_addr));
    //src_address
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = 0; // self pid
    src_addr.nl_groups = NETLINK_IT6604E; // multi cast
    bind(sock_fd, (struct sockaddr*)&src_addr, sizeof(src_addr));
 
    /* Fill the netlink message header */
    nlh=(struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
 
    /* Fill in the netlink message payload */
    iov.iov_base = (void *)nlh;
    iov.iov_len = NLMSG_SPACE(MAX_PAYLOAD);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
}

int main()
{
    int state;
    struct msg_struct *ms;
 
    init_netlink();
 
    // Read message from kernel
 
    memset(nlh,0,NLMSG_SPACE(MAX_PAYLOAD));
    while(1)
    {
        printf(" Waiting message. ...\n");
        state = recvmsg(sock_fd, &msg, 0);
        if(state<0)
        {
            printf("state<1");
        }
        ms = (struct msg_struct *)NLMSG_DATA(nlh);
        printf("Received message:\n");
        printf("video_width:%u\n", ms->video_width);
        printf("video_height:%u\n", ms->video_height);
        printf("video_freq:%u\n", ms->video_freq);
        printf("video_interlaced:%u\n", ms->video_interlaced);
        printf("video_hdcp:%u\n", ms->video_hdcp);
        printf("audio_freq:%u\n", ms->audio_freq);
    }

    close(sock_fd);

    return 0;
}
