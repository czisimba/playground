#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <string.h>
#include <time.h>
#include <errno.h>

int main()
{
    int status;
    pid_t f = fork();
    if (f == 0)
    {
        mqd_t queue;
        char message[20];
        queue = mq_open("/messages", O_WRONLY+O_CREAT,0777, 0);
        strncpy(message, "Hello", 6);
        printf("Send message:%s\n", message);
        mq_send(queue, message ,1, 0);
        //mq_close(queue);
        //mq_unlink("/messages");
        printf("Child process completed\n");
        sleep(2);
    }
    else
    {
        int ret;
        mqd_t queue;
        char message[2000];
        queue = mq_open("/messages", O_RDONLY+O_CREAT, 0777, 0);
        sleep(1);
        //while ((ret = mq_receive(queue, message, 2000, 0)) < 0)
        ret = mq_receive(queue, message, 2000, 0);
        printf("ret:%d errno:%d, Receive message %s\n", ret, errno, message);
        mq_close(queue);
        mq_unlink("/messages");
        printf("Parent process completed\n");
    }

    return 0;
}
