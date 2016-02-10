#include <stdio.h>

#define MAX 9
int used[MAX];
int result[MAX];

void print()
{
    int i;
    for (i = 0;i < MAX;++i)
    {
        printf("%d", result[i]);
    }
    printf("\n");
}

void perm(int step)
{
    int i;
    if (step == MAX) {
        print();
    } 
    else {
        for (i = 0;i < MAX;++i)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                result[step] = i + 1;
                perm(step + 1);
                used[i] = 0;
            } 
        }
    }
}

int main()
{
    perm(0);

    return 0;
}
