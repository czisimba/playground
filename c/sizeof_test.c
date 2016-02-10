#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[30];
    char *p = (char *)malloc(20 * sizeof(char));
    printf("%d\n", sizeof(s));
    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(s[3]));
    printf("%d\n", sizeof(p+3));
    printf("%d\n", sizeof(*(p+4)));

    return 0;
}
