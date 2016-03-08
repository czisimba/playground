#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_SERIAL_DATA_LEN 255
#define __DEBUG__

#ifdef __DEBUG__
#include <stdarg.h>
void debug(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}
#else
void debug(const char *fmt, ...)
{
}
#endif
    
int vtime, vmin, read_len;
int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio,oldtio;
    if(tcgetattr(fd, &oldtio) != 0){
        perror("    SetupSerial 1");
        return -1;
    }
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag |= CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;

    switch(nBits){
        case 7:
            newtio.c_cflag |= CS7;
            break;
        case 8:
            newtio.c_cflag |= CS8;
            break;
    }

    switch(nEvent){
        case 'O':
            newtio.c_cflag |= PARENB;
            newtio.c_cflag |= PARODD;
            newtio.c_iflag |= (INPCK | ISTRIP);
            break;
        case 'E':
            newtio.c_iflag |= (INPCK | ISTRIP);
            newtio.c_cflag |= PARENB;
            newtio.c_cflag &= ~PARODD;
            break;
        case 'N':
            newtio.c_cflag &= ~PARENB;
            break;
    }

    switch(nSpeed){
        case 4800:
            cfsetispeed(&newtio, B4800);
            cfsetospeed(&newtio, B4800);
            break;
        case 9600:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        case 38400:
            cfsetispeed(&newtio, B38400);
            cfsetospeed(&newtio, B38400);
            break;
        case 57600:
            cfsetispeed(&newtio, B57600);
            cfsetospeed(&newtio, B57600);
            break;
        case 115200:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
        default:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
    }

    if(1 == nStop){
        newtio.c_cflag &= ~CSTOPB;
    }else if(2 == nStop){
        newtio.c_cflag |= CSTOPB;
    }

    newtio.c_cc[VTIME] = vtime;
    newtio.c_cc[VMIN] = vmin;// if read 1,read return otherwhise blocked 
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd, TCSANOW, &newtio)) != 0){
        perror("    com set error");
        return -1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    unsigned char data[MAX_SERIAL_DATA_LEN + 1] = {0};
    int data_len = 0;
    int tty_fd;

    vtime = atoi(argv[1]);
    vmin = atoi(argv[2]);
    read_len = atoi(argv[3]);
    // ttyS0
    tty_fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (-1 == tty_fd) {
        syslog(LOG_ERR, "%s:%d, open /dev/ttyS0 fail,errno:%d", __FILE__, __LINE__, errno);
        return -1;    
    }

    if (fcntl(tty_fd, F_SETFL, 0) < 0)// block mode
        syslog(LOG_ERR, "%s:%d, fcntl failed!,errno:%d", __FILE__, __LINE__, errno);
    if (0 == isatty(STDIN_FILENO))
        syslog(LOG_ERR, "%s:%d, standard input is not a terminal device", __FILE__, __LINE__);
    if (set_opt(tty_fd, 115200, 8, 'N', 1) < 0) {
        syslog(LOG_ERR,"%s:%d, set_opt tty error", __FILE__, __LINE__);
        exit(1);
    }

    while (1) {
        data_len = read(tty_fd, data, read_len);
        debug("get a message from rs232,len:%d, message:%s\r\n", data_len, data);
        bzero(data, sizeof(data));
    }

    close(tty_fd);

    exit(0);
}
