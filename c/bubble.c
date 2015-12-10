#include <stdio.h>

int print_array(int *arr, int len)
{
    int i;

    printf("{");
    for (i = 0;i < len - 1;i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d}\n", arr[i]);

    return 0;
}

int sort(int *arr, int len)
{
    int i,j,tmp;

    for (i = 0;i < len;i++)
    {
        for (j = 0;j < len - i - 1;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return 0;
}

#define ARRAY_LEN 12
int main()
{
    int i;
    int array[ARRAY_LEN] = {1,4,2,8,9,  3,7,5,19,10,  6,88};

    printf("origin array:\n");
    print_array(array, ARRAY_LEN);

    sort(array, ARRAY_LEN);

    printf("array after sort:\n");
    print_array(array, ARRAY_LEN);

    return 1;
}
