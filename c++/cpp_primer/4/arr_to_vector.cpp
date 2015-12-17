#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const int arr_size = 10;
int main()
{
    int arr[arr_size] = {1,2,3,8,9,5,7};
    vector<int> v(arr, arr + arr_size);

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
