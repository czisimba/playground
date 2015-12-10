#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    //char ns[50] = "72057594037927936";
    //char ns[50] = "woshishui";
    char ns[50] = "0XA000004414AB0E";
    //char ns[50] = "321335400882092";
    unsigned long long ull = strtoul(ns, NULL, 0);
    //unsigned long long ull = atoi(ns); // shouldn't use atio

    printf("%llx\n", ull);
    printf("%c\n", argv[0][0]);

    return 0;
}
