#include <stdio.h>
#include <openssl/md5.h>
#include <stdlib.h>

int main()
{
	int i = 0;
        FILE *fd=fopen("test","r");
        MD5_CTX c;
        unsigned char md5[17]={0};
        if(fd == NULL)
        {
		printf("open failed");
                return -1;
        }
        int len;
        unsigned char *pData = (unsigned char*)malloc(1024*1024);
        if(!pData)
        {
		printf("malloc failed");
                return -1;
        }
        MD5_Init(&c);
        while( 0 != (len = fread(pData, 1, 1024*1024, fd) ) )
        {
                MD5_Update(&c, pData, len);
        }
        MD5_Final(md5,&c);
        for(i = 0; i < 16; i++)
		printf("%02x", md5[i]);
	printf("\n");
        fclose(fd);
        free(pData);

        return 0;
}
