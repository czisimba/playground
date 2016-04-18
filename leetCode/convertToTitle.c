#include <stdio.h>

char* convertToTitle(int n) {
    int i = 0,j;
    static char s[20];
    char tmp;
    do {
        s[i++] = (n - 1) % 26  + 'A';
        n = (n - 1)/ 26;
    } while (n != 0);
    s[i] = '\0';
    for (j = 0;j < i/2;j++)
    {
        tmp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = tmp;
    }

    return s;
}

int main()
{
    int n = 1;
    char *s;
    s = convertToTitle(n);
    printf("num is [%d],string is [%s]\n", n, s);
    
    return 0;
}
