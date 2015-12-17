#include <iostream>
#include <vector>

using namespace::std;

int main()
{
    vector<int> ivec;
    ivec.push_back(1);

    cout << ivec[0] << endl;
    vector<int>::reference ref = *ivec.begin();
    ref = 2;
    cout << ivec[0] << endl;
    int &ref1 = *ivec.begin();
    ref1 = 3;
    cout << ivec[0] << endl;

    return 0;
}
