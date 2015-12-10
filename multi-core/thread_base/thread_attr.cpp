#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_loop(void* param)
{
    printf("thread loop is excuted\n");

    return NULL;
}

int main()
{
    size_t stacksize;
    pthread_t thread;
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    pthread_attr_getstacksize(&attributes, &stacksize);
    printf("Stack Size = %i\n", stacksize);
    pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread, &attributes, thread_loop, 0);
    pthread_attr_destroy(&attributes);
    //pthread_join(thread, NULL);
    sleep(1);

    return 0;
}
