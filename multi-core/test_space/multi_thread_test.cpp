#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <sys/time.h>

//#define USE_SPINLOCK

#ifdef USE_SPINLOCK
pthread_spinlock_t spinlock;
#else
pthread_mutex_t mutex;
#endif


#define NR_THREAD 10
#define MILLION 1000000L
#define TIMES 100000000
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
    clock_t start,finish;
    float duration;
    start = clock();
    for(i = 0;i<EXEC_TIMES;i++)
    {
#ifdef USE_SPINLOCK
        pthread_spin_lock(&spinlock);
#else
        pthread_mutex_lock(&mutex);
#endif
        
        //little();
        big();
        
#ifdef USE_SPINLOCK
        pthread_spin_unlock(&spinlock);
#else
        pthread_mutex_unlock(&mutex);
#endif
        
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    
#ifdef USE_SPINLOCK
    printf("thread[%d],spin lock cost time :%f\n", int(arg), duration);
#else
    printf("thread[%d],mutex lock cost time :%f\n", int(arg), duration);
#endif
    
    return arg;
}

int main()
{
    int i;
    clock_t start,finish;
    float duration;
    int ret;
#ifdef USE_SPINLOCK
    pthread_spin_init(&spinlock, 0);
#else
    pthread_mutex_init(&mutex,NULL);
#endif
    pthread_t Tid[NR_THREAD];
    
    start = clock();
    for(i = 0;i<NR_THREAD;i++)
    {
        if(pthread_create(&Tid[i],NULL,worker,(void *)i) != 0)
        {
            fprintf(stderr,"pthread create failed\
                    when i = %d\n",i);
            return -1;
        }
    }
                    
    for(i = 0;i<NR_THREAD;i++)
    {
        if(pthread_join(Tid[NR_THREAD - i - 1],(void **)&ret))
        {
            fprintf(stderr,"pthread join failed\
                            when i = %d\n",i);
            return -2;
        }
        printf("ret:%d\n",ret);
    }
                                    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
#ifdef USE_SPINLOCK
    printf("total:spin lock cost time :%f\n", duration);
#else
    printf("total:mutex lock cost time :%f\n", duration);
#endif
                                    

                                                    
    return 0;
}
