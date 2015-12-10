#include <stdio.h>

#define X_LEN 4
#define Y_LEN 4

void swap(int *v1,int *v2)
{
    int tmp;
    tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void revert_arr(int *arr, int x_len, int y_len)
{
    int tmp;
    int x,y,x_end,y_end,rev_x,rev_y;
    int *p,*p_rev;
    if ((x_len & 0x1) == 0x1)
    {
        x_end = (x_len - 1) / 2;
        y_end = y_len / 2;
    }
    else
    {
        x_end = x_len / 2 - 1;
        y_end = y_len - 1;
    }

    for (x = 0; x <= x_end;++x)
    {
        rev_x = x_len - x - 1;
        for (y = 0;y <= y_end;++y)
        {
            p = arr + x * y_len + y;
            p_rev = arr + rev_x * y_len + y_len - y - 1;//rev_y = y_len - y - 1
            swap(p,p_rev);
        }
    }
}

void revert_arr1(int *arr, int x_len, int y_len)
{
    int tmp;
    int idx,middle = (x_len * y_len - 1) / 2;

    for (idx = 0; idx < middle;++idx)
    {
        swap(arr + idx,arr + x_len * y_len - idx - 1);
    }
}

//void print_arr(int arr[][X_LEN], int x_len, int y_len)
void print_arr(int *arr, int x_len, int y_len)
{
    int x,y;
    for (x = 0;x < x_len;++x)
    {
        for (y = 0;y < y_len;++y)
            printf("%4d\t", *(arr + x * y_len + y));
        printf("\n");
    }
}

int main()
{
    int arr[X_LEN][Y_LEN] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16}};
    print_arr((int *)arr, X_LEN, Y_LEN);
    revert_arr1((int *)arr, X_LEN, Y_LEN);
    printf("++++++++++++++++++++++++++++++++++\n");
    print_arr((int *)arr, X_LEN, Y_LEN);

    return 0;
}
