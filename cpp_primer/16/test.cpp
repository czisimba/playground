#include <iostream>
#include <vector>
#include <string>

using namespace::std;

int main()
{
    vector<int> iv;
    vector<int>::iterator iter = iv.begin();
    string::value_type st = 3;
    vector<int>::value_type st1 = 3;
    cout << st << endl;
    cout << st1 << endl;

    return 0;
}
