#include <stdio.h>

int digui(int *value)
{
    if (*value > 0)
    {
        (*value)--;
        return digui(value);
    }
    else
    {
        printf("meet end\n");
    }

    return 0;
}
int main()
{
    int v = 10;

    printf("value is %d\n", v);
    digui(&v);
    printf("value is %d\n", v);

    return 0;
}
