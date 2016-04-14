#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

#define MEM_SIZE (1024 * 1024 * sizeof(int))
int main()
{
    int handle = shm_open("/shm", O_CREAT|O_RDWR, 0777);
    ftruncate(handle, MEM_SIZE);
    char *mem = (char *)mmap(0, MEM_SIZE,
            PROT_READ|PROT_WRITE,MAP_SHARED, handle, 0);
    memset(mem, MEM_SIZE, 0);
    shm_unlink("/shm");

    return 0;
}
