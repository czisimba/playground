#include <stdio.h>
#include <string.h>

int main()
{
    char buf1[100] = "aaa   bbb,ccc|ddd|ok   haha,ooo";
    char *token = strtok(buf1," ,|");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL," ,|");
    }

    return 0;
}
