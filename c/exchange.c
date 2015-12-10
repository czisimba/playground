#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000
#define MIN_VALUE 0
void init_array(int *arr, int len)
{
    int i;

    for (i = 0;i < len;i++)
    {
        arr[i] = rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE;
    }
}

#define MAX_LINE_NUM 20
int print_array(int *arr, int len)
{
    int i;
    int cnt = 0;

    printf("{");
    for (i = 0;i < len;i++)
    {
        if (i != len - 1)
            printf("%4d,", arr[i]);
        else
            printf("%4d}\n", arr[i]);
        if ((i + 1) % MAX_LINE_NUM == 0)
            printf("\n ");
    }

    return 0;
}

int sort(int *arr, int len)
{
    int i,j,tmp;
    int min_idx;

    for (i = 0;i < len - 1;i++)
    {
        min_idx = i;
        for (j = i + 1;j < len;j++)
        {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }

    return 0;
}

#define ARRAY_LEN 100
int main()
{
    int i;
    int array[ARRAY_LEN];

    init_array(array, ARRAY_LEN);

    printf("origin array:\n");
    print_array(array, ARRAY_LEN);

    sort(array, ARRAY_LEN);

    printf("array after sort:\n");
    print_array(array, ARRAY_LEN);

    return 1;
}
