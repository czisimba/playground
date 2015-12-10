#include <stdio.h>
#include <pthread.h>

int main()
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);// shared with multi process
    pthread_mutex_init(&mutex, &attr);
    pthread_mutexattr_destroy(&attr);

    return 0;
}

