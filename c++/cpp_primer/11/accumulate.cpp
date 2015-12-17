#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace::std;

int main()
{
    int sum = 0,ival;
    vector<int> ivec;

    while (cin >> ival)
        ivec.push_back(ival);
    sum = accumulate(ivec.begin(), ivec.end(), 0);
    cout << sum << endl;

    return 0;
}
