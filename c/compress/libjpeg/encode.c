#include <stdio.h>  
#include <stdlib.h>  
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <jpeglib.h>   

#define WIDTH 640
#define HEIGHT 480
#define QUALITY 80  
#define BUFFER_SZIE (WIDTH*HEIGHT*2)  

/* The following declarations and 5 functions are jpeg related  
 *  * functions used by put_jpeg_grey_memory and put_jpeg_yuv420p_memory 
 *   */  
typedef struct {  
    struct jpeg_destination_mgr pub;  
    JOCTET *buf;  
    size_t bufsize;  
    size_t jpegsize;  
} mem_destination_mgr;  

typedef mem_destination_mgr *mem_dest_ptr;  


METHODDEF(void) init_destination(j_compress_ptr cinfo)  
{  
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;  
    dest->pub.next_output_byte = dest->buf;  
    dest->pub.free_in_buffer = dest->bufsize;  
    dest->jpegsize = 0;  
}  

METHODDEF(boolean) empty_output_buffer(j_compress_ptr cinfo)  
{  
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;  
    dest->pub.next_output_byte = dest->buf;  
    dest->pub.free_in_buffer = dest->bufsize;  

    return FALSE;  
}  

METHODDEF(void) term_destination(j_compress_ptr cinfo)  
{  
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;  
    dest->jpegsize = dest->bufsize - dest->pub.free_in_buffer;  
}  

static GLOBAL(void) jpeg_mem_dest_1(j_compress_ptr cinfo, JOCTET* buf, size_t bufsize)  
{  
    mem_dest_ptr dest;  

    if (cinfo->dest == NULL) {  
        cinfo->dest = (struct jpeg_destination_mgr *)  
            (*cinfo->mem->alloc_small)((j_common_ptr)cinfo, JPOOL_PERMANENT,  
                    sizeof(mem_destination_mgr));  
    }  

    dest = (mem_dest_ptr) cinfo->dest;  

    dest->pub.init_destination    = init_destination;  
    dest->pub.empty_output_buffer = empty_output_buffer;  
    dest->pub.term_destination    = term_destination;  

    dest->buf      = buf;  
    dest->bufsize  = bufsize;  
    dest->jpegsize = 0;  
}  

static GLOBAL(int) jpeg_mem_size(j_compress_ptr cinfo)  
{  
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;  
    return dest->jpegsize;  
}  



/* put_jpeg_yuv420p_memory converts an input image in the YUV420P format into a jpeg image and puts 
 *  * it in a memory buffer. 
 *   * Inputs: 
 *    * - input_image is the image in YUV420P format. 
 *     * - width and height are the dimensions of the image 
 *      * Output: 
 *       * - dest_image is a pointer to the jpeg image buffer 
 *        * Returns buffer size of jpeg image      
 *         */  
static int put_jpeg_yuv420p_memory(unsigned char *dest_image,  
        unsigned char *input_image, int width, int height)  
{  
    int i, j, jpeg_image_size;  

    JSAMPROW y[16],cb[16],cr[16]; // y[2][5] = color sample of row 2 and pixel column 5; (one plane)  
    JSAMPARRAY data[3]; // t[0][2][5] = color sample 0 of row 2 and column 5  

    struct jpeg_compress_struct cinfo;  
    struct jpeg_error_mgr jerr;  

    data[0] = y;  
    data[1] = cb;  
    data[2] = cr;  

    cinfo.err = jpeg_std_error(&jerr);  // errors get written to stderr   

    jpeg_create_compress(&cinfo);  
    cinfo.image_width = width;  
    cinfo.image_height = height;  
    cinfo.input_components = 3;  
    jpeg_set_defaults (&cinfo);  

    jpeg_set_colorspace(&cinfo, JCS_YCbCr);  

    cinfo.raw_data_in = TRUE;                  // supply downsampled data  
    cinfo.do_fancy_downsampling = FALSE;       // fix segfaulst with v7  
    cinfo.comp_info[0].h_samp_factor = 2;  
    cinfo.comp_info[0].v_samp_factor = 2;  
    cinfo.comp_info[1].h_samp_factor = 1;  
    cinfo.comp_info[1].v_samp_factor = 1;  
    cinfo.comp_info[2].h_samp_factor = 1;  
    cinfo.comp_info[2].v_samp_factor = 1;  

    jpeg_set_quality(&cinfo, QUALITY, TRUE);  
    cinfo.dct_method = JDCT_FASTEST;  

    jpeg_mem_dest_1(&cinfo, dest_image, BUFFER_SZIE);    // data written to mem  

    jpeg_start_compress (&cinfo, TRUE);  

    for (j = 0; j < height; j += 16) {  
        for (i = 0; i < 16; i++) {  
            y[i] = input_image + width * (i + j);  
            if (i%2 == 0) {  
                cb[i/2] = input_image + width * height + width / 2 * ((i + j) / 2);  
                cr[i/2] = input_image + width * height + width * height / 4 + width / 2 * ((i + j) / 2);  
            }  
        }  
        jpeg_write_raw_data(&cinfo, data, 16);  
    }  

    jpeg_finish_compress(&cinfo);  
    jpeg_image_size = jpeg_mem_size(&cinfo);  
    jpeg_destroy_compress(&cinfo);  

    return jpeg_image_size;  
}  


int main( int argc, char * argv[])  
{  
    FILE* file, *out_file;  
    unsigned char *pSrc ,*pDst;  
    int read_len;  
    int lSize = 0;  
    long long start, finish;
    struct timeval tv1, tv2;

    /* 通过命令行参数将srcfile文件的数据压缩后存放到dstfile文件中 */  
    if(argc < 3)  
    {  
        printf("Usage: zcdemo srcfile dstfile\n");  
        return -1;  
    }  

    if((pSrc = (unsigned char*)malloc(sizeof(unsigned char) * BUFFER_SZIE)) == NULL)  
    {  
        printf("No enough memory!\n");  
        return -1;  
    }  
    if((pDst = (unsigned char*)malloc(sizeof(unsigned char) * BUFFER_SZIE)) == NULL)  
    {  
        printf("No enough memory!\n");  
        return -1;  
    }  
    if((file = fopen(argv[1], "rb")) == NULL)  
    {  
        printf("Can\'t open %s!\n", argv[1]);  
        return -1;  
    }
    /* 装载源文件数据到缓冲区 */  
    read_len = fread(pSrc, sizeof(char), BUFFER_SZIE, file);  

    gettimeofday(&tv1, NULL);
    lSize = put_jpeg_yuv420p_memory(pDst,pSrc , WIDTH ,HEIGHT);  
    gettimeofday(&tv2, NULL);
    start = tv1.tv_sec*1000*1000 + tv1.tv_usec;
    finish = tv2.tv_sec*1000*1000 + tv2.tv_usec;
    printf("encode yuv420p to jpeg cost time:%fms\n", (double)(finish - start) / 1000);
    if((out_file = fopen(argv[2], "wb")) == NULL)  
    {  
        printf("Can\'t create %s!\n", argv[2]);  
        return -1;  
    }  
    fwrite(pDst, sizeof(unsigned char), lSize, out_file);  

    return 0;  
}  
