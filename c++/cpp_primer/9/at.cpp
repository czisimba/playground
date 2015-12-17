#include <iostream>
#include <vector>

using namespace::std;

int main()
{
    vector<int> ivec;
    ivec.push_back(1);

    //ivec.erase(ivec.begin());
    //ivec.clear();
    //ivec.pop_back();
    //ivec.pop_front(); // error, vector not support
    vector<int>::reference ref = ivec.back();
    cout << ref << endl;

    return 0;
}
