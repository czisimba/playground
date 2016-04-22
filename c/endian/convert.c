#include <stdio.h>

#define sw16(x) \
       ((unsigned short)(\
                 (((unsigned short)(x) &(unsigned short)0x00ffU) << 8) |\
                 (((unsigned short)(x) &(unsigned short)0xff00U) >> 8)))

#define sw32(x) \
       ((unsigned int)(\
                 (((unsigned int)(x) &(unsigned int)0x000000ffU) << 24) |\
                 (((unsigned int)(x) &(unsigned int)0x0000ff00U) << 8) |\
                 (((unsigned int)(x) &(unsigned int)0x00ff0000U) >> 8) |\
                 (((unsigned int)(x) &(unsigned int)0xff000000U) >> 24)))

int main()
{
    int i;
    unsigned short s = 0xff02;
    printf("s is %u\n", s);
    for (i = 0;i < 10000000;i++)
        s = sw16(++s);
    printf("s is %u\n", s);

    unsigned int iv = 0xff020304;
    printf("iv is %u\n", i);
    for (i = 0;i < 10000000;i++)
        iv = sw32(++iv);
    printf("iv is %u\n", iv);

    return 0;
}
