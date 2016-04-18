#include <stdio.h>

void my_itoa(int num, char *str)
{
    int i = 0,len;
    char tmp[20];
    while (num != 0)
    {
        tmp[i++] = (num % 10) + '0';
        num /= 10;
    }
    tmp[i] = '\0';
    len = i;
    for (i = 0;i < len;++i) 
    {
        str[i] = tmp[len - i - 1];
    }
    tmp[len] = '\0';
}

int main()
{
    int num = 12345678;
    char str[30];

    my_itoa(num, str);
    printf("str is %s\n", str);

    return 0;
}
