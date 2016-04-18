#include <stdio.h>

int trailingZeroes(int n) {
    int sum = 1,last = 0;
    if (n <= 0)
        return 0;
    for (;n > 0;n--)
    {
        sum *= n;
        if (sum < last)
            return 0;
        last = sum;
    }

    return sum;
}

int main()
{
    int v,n;
    n = 1;
    v = trailingZeroes(n);
    printf("n is %d, v is %d\n",n , v);

    return 0;
}
