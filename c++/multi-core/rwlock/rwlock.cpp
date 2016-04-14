#include <stdio.h>
#include <pthread.h>

#define MATRIX_HIGH 10
#define MATRIX_LENGTH 10
int matrix[MATRIX_HIGH][MATRIX_LENGTH] = {0};

pthread_rwlock_t lock1,lock2;
int readMatrix(int x, int y)
{
    int result;
    pthread_rwlock_rdlock(&lock1);
    result = matrix[x][y];
    pthread_rwlock_unlock(&lock1);//can't find pthread_rwlock_rdunlock 
    return result;
}

void updateMatrix(int x, int y, int value)
{
    pthread_rwlock_wrlock(&lock1);
    matrix[x][y] = value;
    pthread_rwlock_unlock(&lock1);//can't find pthread_rwlock_wrunlock
}

int main()
{
    pthread_rwlockattr_t attr;
    pthread_rwlockattr_init(&attr);
    pthread_rwlockattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);// set rwlock shared
    pthread_rwlock_init(&lock1, 0);
    //lock2 = PTHREAD_RWLOCK_INITIALIZER;// same result with lock1,c++11 style

    pthread_rwlockattr_destroy(&attr);
    pthread_rwlock_destroy(&lock1);
    pthread_rwlock_destroy(&lock2);

    return 0;
}
