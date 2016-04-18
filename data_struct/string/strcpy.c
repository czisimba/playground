#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, char *src)
{
    char *addr = dest;
    if (dest == NULL || src == NULL) return NULL;

    while ((*dest++ = *src++) != '\0') NULL;
    return addr;
}


int main()
{
    char s[10] = "123456789";
    char d[10] = "1234";
    my_strcpy(d, s);
    printf("%s,\n%s\n", s, d);

    return 0;
}
