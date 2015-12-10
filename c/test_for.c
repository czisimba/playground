#include <stdio.h>

void main()
{
    int i = 0;

    for (i = 0;i < 3;i++)
    {
        if (i == 3)
            break;
    }
    printf("i is %d\n", i);
}
