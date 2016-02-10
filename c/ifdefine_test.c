#include <stdio.h>

int v = 0;


#define AAA
int main()
{
#ifndef  AAA
    v = 1;
#elif defined BBB
    v = 2;
#else
    v = 3;
#endif
    printf("v is %d\n", v);

    return 0;
}
