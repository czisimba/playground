#include <stdio.h>
#include <string.h>

#define STR_MAX_LEN 100

char *str_move(char *str, int steps)
{
    int len = strlen(str);
    char tmp[STR_MAX_LEN]; 
    steps = steps % len;
    memcpy(tmp + len - steps, str, steps);
    memcpy(tmp, str + steps, len - steps);
    memcpy(str, tmp, len);

    return str;
}

int main()
{
    char s[] = "12345678";
    int steps = 4;
    str_move(s, steps);
    printf("str:[%s]\n", s);

    return 0;
}
