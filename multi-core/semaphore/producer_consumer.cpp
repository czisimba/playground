#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t semaphore,semaphore1;
sem_t limit;
pthread_mutex_t mutex;

int stack_length = 0;
int stack[20];
int producer_loop = 0;

void *producer(void *param)
{
    int i = 0;
    for (i = 0;i < 100; ++i)
    {
        // if stack is 10,wait until consumer pop
        sem_wait(&limit);
        pthread_mutex_lock(&mutex);
        stack[stack_length++] = i;
        pthread_mutex_unlock(&mutex);
        usleep(100);
        sem_post(&semaphore);
    }
}

void *consumer(void *param)
{
    int item = 0;
    for (int i = 0;i < 100; ++i)
    {
        // if stack empty,wait
        if (stack_length == 0)
            sem_wait(&semaphore);
        pthread_mutex_lock(&mutex);
        item = stack[--stack_length]; 
        pthread_mutex_unlock(&mutex);
        usleep(1000);
        printf("Received %i\n", item);
        sem_post(&limit);
    }
}

int main()
{
    pthread_t producer_thread,consumer_thread;
    pthread_mutex_init(&mutex, 0);// shared with multi process
    sem_init(&semaphore, 0, 0);
    sem_init(&limit, 0, 10);
    pthread_create(&producer_thread, 0, producer, 0);
    pthread_create(&consumer_thread, 0, consumer, 0);
    pthread_join(producer_thread, 0);
    pthread_join(consumer_thread, 0);
    sem_destroy(&limit);
    sem_destroy(&semaphore);

    return 0;
}
