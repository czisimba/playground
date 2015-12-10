#include <iostream>
#include <vector>
#include <list>

using namespace::std;

int main()
{
    vector<int> ivec;
    cout << "vector size:" << ivec.size() << endl;
    cout << "vector max size:" << ivec.max_size() << endl;
    ivec.resize(100);
    cout << "vector size(after resize to 100):" << ivec.size() << endl;
    cout << "vector max size:" << ivec.max_size() << endl;

    return 0;
}
