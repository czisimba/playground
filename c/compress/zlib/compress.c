#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <zlib.h>  

int main(int argc, char* argv[])  
{  
    FILE* file;  
    uLong flen;  
    unsigned char* fbuf = NULL;  
    uLong clen;  
    unsigned char* cbuf = NULL;  
    long long start, finish;
    struct timeval tv1, tv2;

    /* 通过命令行参数将srcfile文件的数据压缩后存放到dstfile文件中 */  
    if(argc < 3)  
    {  
        printf("Usage: zcdemo srcfile dstfile\n");  
        return -1;  
    }  

    if((file = fopen(argv[1], "rb")) == NULL)  
    {  
        printf("Can\'t open %s!\n", argv[1]);  
        return -1;  
    }  
    /* 装载源文件数据到缓冲区 */  
    fseek(file, 0L, SEEK_END);    /* 跳到文件末尾 */  
    flen = ftell(file);        /* 获取文件长度 */  
    flen = 1920 * 1080 * 3 / 2;
    fseek(file, 0L, SEEK_SET);  
    if((fbuf = (unsigned char*)malloc(sizeof(unsigned char) * flen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        fclose(file);  
        return -1;  
    }  
    fread(fbuf, sizeof(unsigned char), flen, file);  
    /* 压缩数据 */  
    clen = compressBound(flen);  
    if((cbuf = (unsigned char*)malloc(sizeof(unsigned char) * clen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        fclose(file);  
        return -1;  
    }  
    gettimeofday(&tv1, NULL);
    if(compress(cbuf, &clen, fbuf, flen) != Z_OK)  
    {  
        printf("Compress %s failed!\n", argv[1]);  
        return -1;  
    }  
    gettimeofday(&tv2, NULL);
    start = tv1.tv_sec*1000*1000 + tv1.tv_usec;
    finish = tv2.tv_sec*1000*1000 + tv2.tv_usec;
    printf("compress cost time:%fms\n", (double)(finish - start) / 1000);
    fclose(file);  

    if((file = fopen(argv[2], "wb")) == NULL)  
    {  
        printf("Can\'t create %s!\n", argv[2]);  
        return -1;  
    }  
    /* 保存压缩后的数据到目标文件 */  
    fwrite(&flen, sizeof(uLong), 1, file);    /* 写入源文件长度 */  
    fwrite(&clen, sizeof(uLong), 1, file);    /* 写入目标数据长度 */  
    fwrite(cbuf, sizeof(unsigned char), clen, file);  
    fclose(file);  

    free(fbuf);  
    free(cbuf);  

    return 0;  
}  
