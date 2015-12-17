#include <stdio.h>

int i = 3;
const int ic = i;
const int *pic = &ic;
int *const cpi = &i;
const int *const cpic = &ic;

int main()
{

    return 0;
}
