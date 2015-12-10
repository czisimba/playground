#include <stdio.h>

int main()
{
    char str[100] = {0};
    sprintf(str, "tianqi:%s,wendu:%d", "duoyun", 0);
    printf("%s\n", str);

    return 0;
}
