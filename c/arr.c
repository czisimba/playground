#include <stdio.h>
#include <string.h>

int main()
{
    char name[5][10];

    strcpy(name[0], "chengzhi");
    strcpy(name[1], "chengcai");
    strcpy(name[2], "chengding");
    strcpy(name[3], "chengjin");
    strcpy(name[4], "chenghua");

    printf("%s\n", name[0]);
    printf("%s\n", name[1]);
    printf("%s\n", name[2]);
    printf("%s\n", name[3]);
    printf("%s\n", name[4]);

    return 0;
}
