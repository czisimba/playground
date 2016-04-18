#include <stdio.h>

int myAtoi(char* str) {
    int sum = 0,sign = -1,num_start = 0;

    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            sum = sum * 10 + *str - '0';
            num_start = 1;
        }
        else if (*str == ' ')
        {
            if (num_start == 1)
                break;
        }
        else if (*str == '+')
        {
            if (sign != -1)
                break;
            sign = 0;
        }
        else if (*str == '-')
        {
            if (sign != -1)
                break;
            sign = 1;
        }
        else
            break;
        str++;
    }

    return sign == 1 ? -sum : sum;
}

int main()
{
    char str[] = "2147483648";
    //char str[] = "  -0012a42";
    int num;
    num = myAtoi(str);
    printf("str is [%s], num is %d\n", str, num);

    return 0;
}
