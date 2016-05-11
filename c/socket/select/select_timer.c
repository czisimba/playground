#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>


int main()
{
    struct timeval timeout;
    clock_t start, finish;
    double duration;
    int fd = open("./tmp", O_RDWR);

    timeout.tv_sec  = 3;
    timeout.tv_usec = 0;

    start = clock();
    int ret = select(fd+1, NULL, NULL, NULL, &timeout);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    if ( ret == 0 ) {
        printf("Time out,%d,%lu, %lu, cost time:%f\n", CLOCKS_PER_SEC, finish, start, duration);
    } else if ( ret < 0) {
        printf("Socket Error\n");
    } 
    close(fd);

    return 0;
}
