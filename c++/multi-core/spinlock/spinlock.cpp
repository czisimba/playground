#include <stdio.h>
#include <pthread.h>

pthread_spinlock_t lock;

void* lockandunlock(void *param)
{
    int i = 10000;
    int count = 0;
    while (i > 0)
    {
        //pthread_spin_lock(&lock);
        if (pthread_spin_trylock(&lock) == 0)// try and return
        {
            i--;
            pthread_spin_unlock(&lock);
        }
        else
            count++;
    }
    printf("Count is %d\n", count);
}

int main()
{
    pthread_t thread1,thread2;
    //pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);
    pthread_spin_init(&lock, PTHREAD_PROCESS_SHARED);// shared with multi process
    pthread_create(&thread1, NULL, lockandunlock, NULL);
    pthread_create(&thread2, NULL, lockandunlock, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_spin_destroy(&lock);

    return 0;
}

