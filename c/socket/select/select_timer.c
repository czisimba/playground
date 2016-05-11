#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <fcntl.h>

void sleep_us(unsigned int usec)
{
    struct timeval timeout;
    timeout.tv_sec  = 0;
    timeout.tv_usec = usec;
    select(1, NULL, NULL, NULL, &timeout);
}

int main()
{
    int i;
    long long start, finish;
    struct timeval tv1, tv2;

    gettimeofday(&tv1, NULL);
    for (i = 0;i < 10000;i++)
        sleep_us(1000);
    gettimeofday(&tv2, NULL);
    start = tv1.tv_sec*1000*1000 + tv1.tv_usec;
    finish = tv2.tv_sec*1000*1000 + tv2.tv_usec;
    printf("Time out,cost time:%lluus\n", finish - start);

    return 0;
}
