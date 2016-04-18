#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0,count = 1;
    char str[50] = "1233422222";
    char target[50] = {'\0'};

    while (str[i] != '\0')
    {
        if (str[i+1] == str[i])
            count++;
        else
        {
            sprintf(target + strlen(target), "%c%d", str[i], count);
            count = 1;
        }
        i++;
    }
    printf("%s\n", target);

    return 0;
}
