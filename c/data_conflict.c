#include <stdio.h>
#include <pthread.h>

int count = 0;
void * func(void *param)
{
    count++;

    return NULL;
}

int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1, 0, func, 0);
    pthread_create(&thread2, 0, func, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    printf("count is %d\n", count);

    return 0;
}
