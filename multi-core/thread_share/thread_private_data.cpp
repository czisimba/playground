#include <iostream>
#include <pthread.h>
#include <time.h>

__thread int mydata;
//int mydata;

void *thread_func(void *param)
{
    mydata = 1;
    sleep(2);
    printf("mydata is %d\n", mydata );
    return NULL;
}

void *thread_func1(void *param)
{
    sleep(1);
    mydata = 2;
    printf("mydata is %d\n", mydata);
    return NULL;
}

int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1, 0, thread_func, 0);
    pthread_create(&thread2, 0, thread_func1, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    return 0;
}
