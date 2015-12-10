#include <stdio.h>
#include <string.h>

int main()
{
    char line[1024];
    int line_num = 1;
    FILE *fp = fopen("./ipaddr", "r+");
    while (fgets(line,1023,fp))
    {
        printf("%4d: %s", line_num, line);
        line_num++;
    }

    return 0;
}
