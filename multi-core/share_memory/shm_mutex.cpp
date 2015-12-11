#include <stdio.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int main()
{
    pthread_mutex_t *mutex;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    int handle = shm_open("/shm", O_CREAT|O_RDWR, 0777);
    ftruncate(handle,1024*sizeof(int));
    char *mem = (char *)mmap(0, 1024*sizeof(int), PROT_READ|PROT_WRITE,
            MAP_SHARED, handle, 0);
    mutex = (pthread_mutex_t *)mem;
    pthread_mutex_init(mutex, &attr);
    pthread_mutexattr_destroy(&attr);

    int ret = 0;
    int *pcount = (int *)(mem + sizeof(pthread_mutex_t));
    *pcount = 0;
    pid_t pid = fork();
    if (pid == 0)
    {
        //child process
        pthread_mutex_lock(mutex);
        (*pcount)++;
        pthread_mutex_unlock(mutex);
        ret = 57;
    }
    else
    {
        int status;
        waitpid(pid,&status, 0);
        printf("child returned %i\n", WEXITSTATUS(status));
        pthread_mutex_lock(mutex);
        (*pcount)++;
        pthread_mutex_unlock(mutex);
        printf("Count = %i\n", *pcount);
    }

    munmap(mem, 1024*sizeof(int));
    shm_unlink("/shm");
    return ret;
}
