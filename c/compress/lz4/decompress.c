#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <lz4.h>  

int main(int argc, char* argv[])  
{  
    FILE* file, *out_file;  
    int flen = 640 * 480 * 3 / 2;  
    char* fbuf = NULL;  
    int ulen_exp, ulen;  
    char* ubuf = NULL;  
    long long start, finish;
    struct timeval tv1, tv2;
    int out_file_num = 0;
    char out_filename[101];

    if((fbuf = (char*)malloc(sizeof(char) * flen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        return -1;  
    }  
    /* 解压缩数据 */  
    if((ubuf = (char*)malloc(sizeof(char) * flen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        return -1;  
    }  
    /* 通过命令行参数将srcfile文件的数据解压缩后存放到dstfile文件中 */  
    if(argc < 2)
    {  
        printf("Usage: zudemo srcfile\n");  
        return -1;  
    }  

    if((file = fopen(argv[1], "rb")) == NULL)  
    {  
        printf("Can\'t open %s!\n", argv[1]);  
        return -1;  
    }  
    /* 装载源文件数据到缓冲区 */  
    while (fread(&ulen_exp, sizeof(int), 1, file) == 1) {/* 获取缓冲区大小 */  
        fread(&flen, sizeof(int), 1, file);   /* 获取数据流大小 */  
        fread(fbuf, sizeof(char), flen, file);  
        gettimeofday(&tv1, NULL);
        if((ulen = LZ4_decompress_safe(fbuf, ubuf, flen, ulen_exp)) < 0)  
        {  
            printf("Uncompress %s failed!ulen:%d\n", argv[1], ulen);  
            return -1;  
        }  
        gettimeofday(&tv2, NULL);
        start = tv1.tv_sec*1000*1000 + tv1.tv_usec;
        finish = tv2.tv_sec*1000*1000 + tv2.tv_usec;
        printf("uncompress cost time:%fms\n", (double)(finish - start) / 1000);

        sprintf(out_filename, "%d.yuv", out_file_num++);
        if((out_file = fopen(out_filename, "wb")) == NULL)  
        {  
            printf("Can\'t create %s!\n", argv[2]);  
            return -1;  
        }  
        /* 保存解压缩后的数据到目标文件 */  
        fwrite(ubuf, sizeof(unsigned char), ulen, out_file);  
        fclose(out_file);  
    }

    //free(fbuf);  
    //free(ubuf);  

    return 0;  
} 
