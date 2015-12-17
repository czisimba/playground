#include <iostream>
#include <pthread.h>

int main()
{
    //通过默认条件建锁
    pthread_mutex_t *theMutex = new pthread_mutex_t; 
    pthread_mutexattr_t attr; 
    pthread_mutexattr_init(&attr); 
    pthread_mutex_init(theMutex,&attr); 
    pthread_mutexattr_destroy(&attr); 

    // 递归加锁
    pthread_mutex_lock (theMutex); 
    pthread_mutex_lock (theMutex); 
    pthread_mutex_unlock (theMutex); 
    pthread_mutex_unlock (theMutex);
    return 0;
}
