#include <stdio.h>

int main()
{
    FILE *fp = fopen("./aa", "r+");
    perror("error occure");//error code sting follow our string,terminal show:"error occure:No such file or directory"
    return 0;
}
