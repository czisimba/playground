#include <stdio.h>

int string_max(char *s)
{
    char c = '\0';//'\0' cant't be char in string
    int i = 0,len = 0, max_len = 0;
    if (s == NULL)
        return 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            len++;
        else
        {
            if (len > max_len)
                max_len = len;
            len = 1;
            c = s[i];
        }
        i++;
    }
    if (len > max_len)
        max_len = len;

    return max_len;
}

int main()
{
    char s[80] = "abcdeeeebbbbasdfadfafdqergggggggggg";
    int max_len;
    max_len = string_max(s);
    printf("string[%s] max sub_string len is:[%d]\n", s, max_len);
    
    return 0;
}
