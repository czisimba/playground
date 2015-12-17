#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
    vector<int> ivec;
    cout << ivec.capacity() << endl;
    ivec.push_back(1);
    cout << ivec.capacity() << endl;

    return 0;
}
