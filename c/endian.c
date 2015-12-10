#include <stdio.h>
int is_big_endian()
{
    short val = 1;
    return *(unsigned char *)&val != 1 ? 1 : 0;
}

int main()
{
    int endian;
    endian = is_big_endian();

    printf("system is %s endian\n", endian == 1 ? "big" : "little");

    return 0;
}
