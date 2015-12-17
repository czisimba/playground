#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace::std;

int main()
{
    double sum = 0,ival;
    vector<double> ivec;

    while (cin >> ival)
        ivec.push_back(ival);
    sum = accumulate(ivec.begin(), ivec.end(), 0.0);
    cout << sum << endl;

    return 0;
}
