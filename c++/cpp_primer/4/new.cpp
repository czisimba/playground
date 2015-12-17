#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int input;
    vector<int> v;
    while (cin >> input)
    {
        v.push_back(input);
    }

    int *arr = new int[v.size()];
    for (vector<int>::size_type idx = 0; idx != v.size(); ++idx)
    {
        arr[idx] = v[idx];
        cout << arr[idx] << endl;
    }

    return 0;
}
