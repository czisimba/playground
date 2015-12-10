#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <sys/time.h>
#include <libkern/OSAtomic.h>

//#define USE_SPINLOCK

#ifdef USE_SPINLOCK
OSSpinLock spinlock;
#else
pthread_mutex_t mutex;
#endif


#define NR_THREAD 10
#define MILLION 1000000L
#define TIMES 1000000
#define EXEC_TIMES 1

unsigned long long counter = 0;

inline void little()
{
    counter++;
}

inline void big()
{
    int j;
    for(j = 0;j<TIMES;j++)
    {
        counter++;
    }
}

void * worker(void* arg)
{
    int i;
    for(i = 0;i<EXEC_TIMES;i++)
    {
#ifdef USE_SPINLOCK
        OSSpinLockLock(&spinlock);
#else
        pthread_mutex_lock(&mutex);
#endif
        
        //little();
        big();
        
#ifdef USE_SPINLOCK
        OSSpinLockUnlock(&spinlock);
#else
        pthread_mutex_unlock(&mutex);
#endif
        
    }
    
    return NULL;
}

int main()
{
    int i;
    struct timeval tv_start,tv_end;
    unsigned long long interval = 0;
#ifdef USE_SPINLOCK
    spinlock = 0;
#else
    pthread_mutex_init(&mutex,NULL);
#endif
    pthread_t Tid[NR_THREAD];
    
    gettimeofday(&tv_start,NULL);
    for(i = 0;i<NR_THREAD;i++)
    {
        if(pthread_create(&Tid[i],NULL,worker,NULL) != 0)
        {
            fprintf(stderr,"pthread create failed\
                    when i = %d\n",i);
            return -1;
        }
    }
                    
    for(i = 0;i<NR_THREAD;i++)
    {
        if(pthread_join(Tid[i],NULL))
        {
            fprintf(stderr,"pthread join failed\
                            when i = %d\n",i);
            return -2;
        }
    }
                                    
    gettimeofday(&tv_end,NULL);
    interval = MILLION*(tv_end.tv_sec - tv_start.tv_sec )
                + (tv_end.tv_usec - tv_start.tv_usec);
                                    
#ifdef USE_SPINLOCK
    fprintf(stderr,"thread num %d spinlock version \
                        cost time %llu\n",NR_THREAD,interval);
#else
    fprintf(stderr,"thread num %d mutex version \
                       cost time %llu\n",NR_THREAD,interval);
#endif
                                                    
    return 0;
}
