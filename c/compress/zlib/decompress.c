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
    uLong ulen;  
    unsigned char* ubuf = NULL;  
    long long start, finish;
    struct timeval tv1, tv2;

    /* 通过命令行参数将srcfile文件的数据解压缩后存放到dstfile文件中 */  
    if(argc < 3)  
    {  
        printf("Usage: zudemo srcfile dstfile\n");  
        return -1;  
    }  

    if((file = fopen(argv[1], "rb")) == NULL)  
    {  
        printf("Can\'t open %s!\n", argv[1]);  
        return -1;  
    }  
    /* 装载源文件数据到缓冲区 */  
    fread(&ulen, sizeof(uLong), 1, file);   /* 获取缓冲区大小 */  
    fread(&flen, sizeof(uLong), 1, file);   /* 获取数据流大小 */  
    if((fbuf = (unsigned char*)malloc(sizeof(unsigned char) * flen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        fclose(file);  
        return -1;  
    }  
    fread(fbuf, sizeof(unsigned char), flen, file);  
    /* 解压缩数据 */  
    if((ubuf = (unsigned char*)malloc(sizeof(unsigned char) * ulen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        fclose(file);  
        return -1;  
    }  
    gettimeofday(&tv1, NULL);
    if(uncompress(ubuf, &ulen, fbuf, flen) != Z_OK)  
    {  
        printf("Uncompress %s failed!\n", argv[1]);  
        return -1;  
    }  
    gettimeofday(&tv2, NULL);
    start = tv1.tv_sec*1000*1000 + tv1.tv_usec;
    finish = tv2.tv_sec*1000*1000 + tv2.tv_usec;
    printf("uncompress cost time:%fms\n", (double)(finish - start) / 1000);
    fclose(file);  

    if((file = fopen(argv[2], "wb")) == NULL)  
    {  
        printf("Can\'t create %s!\n", argv[2]);  
        return -1;  
    }  
    /* 保存解压缩后的数据到目标文件 */  
    fwrite(ubuf, sizeof(unsigned char), ulen, file);  
    fclose(file);  

    free(fbuf);  
    free(ubuf);  

    return 0;  
} 
