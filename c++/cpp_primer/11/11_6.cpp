#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace::std;

int main()
{
    double sum = 0,ival;
    vector<double> ivec;

    ivec.push_back(1.1);
    ivec.push_back(2.1);
    ivec.push_back(3.1);
    ivec.push_back(4.1);
    ivec.push_back(5.1);

    fill_n(ivec.begin(), ivec.size(), 0);
    for (vector<double>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
