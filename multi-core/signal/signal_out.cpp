#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void hsignal(int signal)
{
    //write(1, "Got signal\n", 11);
    printf("Got signal\n");
}

int main()
{
    signal(SIGRTMIN + 4, hsignal);
    kill(getpid(), SIGRTMIN + 4);

    return 0;
}
