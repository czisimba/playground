/*
 * errno has different value in different thread
 */
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

void *thread1(void *param)
{
    FILE *fd = fopen("", "w");
    if (!fd)
        printf("thread1 %4i\n", errno);// thread1
    else
        fclose(fd);
    printf("thread1 %4i\n", errno);
}

int main()
{
    pthread_t thread_data1;
    int i;
    pthread_create(&thread_data1, NULL, thread1, NULL);
    FILE *fd = fopen("join.cpp", "r");
    if (!fd)
        printf("main %4i\n", errno);// main thread
    else
        fclose(fd);
    printf("main %4i\n", errno);
    pthread_join(thread_data1, NULL);
            
    return 0;
}
