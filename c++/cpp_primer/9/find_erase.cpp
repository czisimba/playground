#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
    vector<int> ivec;
    ivec.push_back(1);

    cout << ivec.size() << endl;
    vector<int>::iterator iter = find(ivec.begin(), ivec.end(), 1);
    ivec.erase(iter);
    cout << ivec.size() << endl;

    return 0;
}
