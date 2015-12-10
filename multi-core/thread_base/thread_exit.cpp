#include <stdio.h>
#include <pthread.h>

void *thread1_func(void *param)
{
    printf("In thread1 func\n");
}

int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_detach(thread1);
    printf("In main thread\n");
    pthread_exit(0);// wait until all child thread is exit,even child thread is detached

    return 0;
}
