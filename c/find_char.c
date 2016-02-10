#include <stdio.h>

int get_char_index(char *s, char c, int start, int len)
{
    int i;
    if (s == NULL)
        return -1;
    for (i = start;i < start + len;++i)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

int main()
{
    char s[20] = "abcdefjefj", target = 'j';
    int idx;

    idx = get_char_index(s, target, 1, 15);
    if (idx != -1)
        printf("first '%c' in [%s] index is %d\n", target, s, idx);
    else
        printf("cant' find '%c' in [%s]\n", target, s);

    return 0;
}
