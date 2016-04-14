#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
volatile int counter = 0;// different without lock(single or multi core)
//int counter = 0;// same without lock at single core

void *count(void *param)
{
    for (int i = 0;i < 10000000; ++i)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        //printf("Count:%d\n", counter);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex, 0);
    pthread_create(&thread1, NULL, count, NULL);
    pthread_create(&thread2, NULL, count, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Count:%d\n", counter);
    pthread_mutex_destroy(&mutex);

    return 0;
}
