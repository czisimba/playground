#include <stdio.h>

void string_revert(char *s)
{
    char tmp;
    int i = 0,len = 0;
    while (s[i] != '\0')
    {
        len++;
        i++;
    }
    printf("before revert:%s\n", s);
    for (i = 0;i < len / 2;++i)// mirror with middle index
    {
        tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
    printf("after revert:%s\n", s);
}

int main()
{
    char s[20] = "abcdefghijkl";
    string_revert(s);

    return 0;
}
