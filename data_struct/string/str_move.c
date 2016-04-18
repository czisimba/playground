#include <stdio.h> 
#include <string.h>

void fun(char *w, int m)
{
    int i = 0,len = strlen(w);
    if (m > len) m = len;
    while (len - m > 0 || (m = 0) != 0)
    {
        for (i = 0,w[len] = w[0],++m;i < len;i++)
            w[i] = w[i+1];
    }
    w[len - m] = '\0';
}

int main()
{
    char s[] = "ABCDEFGHI";
    printf("origin string:[%s]\n", s);
    fun(s,3);
    printf("after string:[%s]\n", s);

    return 0;
}
