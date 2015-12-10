#include <stdio.h>

void str_revert(char *s)
{
    int i,mid,len;
    char *t = s,tmp;
    while (*t++ != '\0')
    {
        //...
    }

    len = t - 1 - s;
    mid = (len - 1) / 2;
    for (i = 0;i <= mid;i++)
    {
        tmp = *(s + i);
        *(s + i) = *(s + len - i - 1);
        *(s + len - i - 1) = tmp;
    }
}
int main()
{
    char str[100] = "woshicz";
    str_revert(str);
    printf("%s\n", str);

    return 0;
}
