#include <stdio.h>

int my_atoi(char *s)
{
    int i,v;
    int sum = 0;
    if (s == NULL)
        return 0;
    for (i = 0;i < 10;++i)
    {
        if (s[i] == '\0')
            break;
        v = s[i] - '0';
        if (v >= 0 && v <= 9)
        {
            sum = sum*10 + v;
        }
    }

    return sum;
}

int main()
{
    char s[10] = "22452309";
    int sum;
    sum = my_atoi(s);
    printf("%s,result:%d", s, sum);

    return 0;
}
