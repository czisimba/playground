#include <stdio.h>

int main()
{
    char *buffer = new char[128];
    char buffer_local[128];
    static char buffer_static[128];

    printf("buffer:%p\n", buffer);
    printf("buffer_local:%p\n", buffer_local);
    printf("buffer_static:%p\n", buffer_static);

    return 0;
}
