#include <stdio.h>

#define ARRAY_SIZE 10
int get_second(int *arr, int arr_size)
{
    int i;
    int first =  -1,second = -1;
    for (i = 0;i < arr_size;++i)
    {
        if (*(arr + i) > second)
        {
            if (*(arr + i) > first)
            {
                second = first;
                first = *(arr + i);
            }
            else
            {
                second = *(arr + i);
            }
        }
    }

    return second;
}

int main()
{
    int arr[ARRAY_SIZE] = {1,2,3,4,5,6,7};
    printf("%d\n", get_second(arr, ARRAY_SIZE));

    return 0;
}
