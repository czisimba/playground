#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define IA_SIZE 100000
void init(int ia[], int len)
{
    srand( (unsigned int)time(0) );
    for (int i = 0;i < len;++i)
    {
        ia[i] = rand() % 10000;
    }
}

void print(int ia[], int len)
{
    for (int i = 0;i < len;++i)
    {
        printf("%3d\t", ia[i]);
        if ((i+1) % 20 == 0)
            printf("\n");
    }
}

void sort(int ia[], int len)
{
    int tmp;
    for (int i = 0;i < len - 1;i++)
    {
        for (int j = len - 1; j > i;j--)
        {
            if (ia[j] < ia[j-1])
            {
                tmp = ia[j];
                ia[j] = ia[j-1];
                ia[j-1] = tmp;
            }
        }
    }
}

int main()
{
    int ia[IA_SIZE] = {0};
    clock_t start, finish;
    double duration;

    init(ia,IA_SIZE);
    start = clock();
    sort(ia,IA_SIZE);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    print(ia,IA_SIZE);
    printf("cost time :%f\n", duration);
    
    return 0;
}
