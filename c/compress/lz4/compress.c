#include <stdlib.h>  
#include <stdio.h>  
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <lz4.h>  
#include <lz4hc.h>  

int main(int argc, char* argv[])  
{  
    FILE* file, *out_file;  
    int flen = 640 * 480 * 3, read_len;  
    char* fbuf = NULL;  
    int clen;  
    char* cbuf = NULL;  
    long long start, finish;
    struct timeval tv1, tv2;
    struct dirent    *dp;
    DIR              *dfd;
    char             path[101] = {0};

    /* 通过命令行参数将srcfile文件的数据压缩后存放到dstfile文件中 */  
    if(argc < 2)  
    {  
        printf("Usage: zcdemo dstfile\n");  
        return -1;  
    }  

    if((fbuf = (char*)malloc(sizeof(unsigned char) * flen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        return -1;  
    }  
    if((cbuf = (char*)malloc(sizeof(unsigned char) * flen)) == NULL)  
    {  
        printf("No enough memory!\n");  
        return -1;  
    }  

    if((out_file = fopen(argv[1], "wb")) == NULL)  
    {  
        printf("Can\'t create %s!\n", argv[2]);  
        return -1;  
    }  


    strcpy(path,"./");
    if( (dfd = opendir(path)) == NULL )
    {
        printf("open dir failed! dir: %s", path);
        return - 1;
    }
    for(dp = readdir(dfd); NULL!=dp; dp = readdir(dfd))
    {   
        if (strncmp(dp->d_name,"P_640x480", 9) == 0)
        {
            if((file = fopen(dp->d_name, "rb")) == NULL)  
            {  
                printf("Can\'t open %s!\n", argv[1]);  
                return -1;  
            }
            /* 装载源文件数据到缓冲区 */  
            read_len = fread(fbuf, sizeof(unsigned char), flen, file);  
            /* 压缩数据 */  
            clen = LZ4_compressBound(read_len);  
            gettimeofday(&tv1, NULL);
            if((clen = LZ4_compress(fbuf, cbuf, read_len)) < 0)  
            {  
                printf("Compress %s failed!\n", argv[1]);  
                return -1;  
            }  
            gettimeofday(&tv2, NULL);
            start = tv1.tv_sec*1000*1000 + tv1.tv_usec;
            finish = tv2.tv_sec*1000*1000 + tv2.tv_usec;
            printf("compress cost time:%fms\n", (double)(finish - start) / 1000);
            fclose(file);  
            /* 保存压缩后的数据到目标文件 */  
            fwrite(&read_len, sizeof(int), 1, out_file);    /* 写入源文件长度 */  
            fwrite(&clen, sizeof(int), 1, out_file);    /* 写入目标数据长度 */  
            fwrite(cbuf, sizeof(char), clen, out_file);  
        }
    }

    fclose(out_file);
    free(fbuf);
    free(cbuf);

    return 0;
}  
