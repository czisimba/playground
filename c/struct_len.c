#include <stdio.h>

typedef struct test_len_s {
    char k;
    long a;
    int b;
    char c;
} test_len_t;

int main()
{
    printf("strct len is %lu\n", sizeof(test_len_t));
    return 0;
}
