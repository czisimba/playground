#ifndef _TFTPD_H_
#define _TFTPD_H_
#include <stdio.h>

#define RRQ 1
#define WRQ 2
#define DATA 3
#define ACK 4
#define ERROR 5

#define ERROR_CODE_FILE_NOTFOUND 1
typedef struct init_msg_s {
    unsigned short opcode;
    unsigned short error_code;
    unsigned int len;
    char filename[0];
} init_msg_t;

typedef struct datablock_s {
    unsigned short opcode;
    unsigned short blocknum;
    char data[0];
} datablock_t;

#define SERVPORT 5050
#define CLIENT_TFTP_PORT 7099

#define MAX_FILENAME_LEN 100

#endif /*_TFTPD_H_*/
