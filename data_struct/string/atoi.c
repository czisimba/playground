#include <stdio.h>

int my_atoi(char *str)
{
    int sum = 0;
    if (str == NULL) return 0;
    while (*str != '\0')
    {
        sum = sum * 10 + *str - '0';
        str++;
    }

    return sum;
}

int main()
{
    int num;
    char str[] = "12345678";
    num = my_atoi(str);
    printf("num is %d\n", num);

    return 0;
}
