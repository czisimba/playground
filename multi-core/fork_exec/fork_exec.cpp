#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;
    //printf("not fork\n");
    pid_t f = fork();
    //printf("after fork\n");
    if (f == 0)// child process
    {
        execl("/bin/sleep", "/bin/sleep", "5");
    }
    else// fatherprocess
    {
        waitpid(f, &status, 0);
        printf("Status = %i\n", status);
    }

    return 0;
}
