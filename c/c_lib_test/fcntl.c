#include <stdio.h>
#include <unistd.h>//read
#include <fcntl.h>//O_RDWR

#define TEST_FILE "/dev/ttyUSB0"
//#define TEST_FILE "aa"
int main()
{
    char c,i;
    int rt;
    int fd = open(TEST_FILE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0)
        perror(TEST_FILE);
    if (fcntl(fd,F_SETFL, 0) < 0)//set fd to BLOCK mode 
	perror("fcntl");
    for (i = 1;i < 10;i++)
    {
        rt = read(fd, &c ,1);
        printf("%d time,char is %d,rt is:%d\n", i, c, rt);
    }

    return 0;
}
