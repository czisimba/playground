#include <iostream>
#include <vector>

using namespace::std;

int main()
{
    vector<int> ivec1;
    vector<int> ivec2;
    ivec1.push_back(1);
    ivec1.push_back(2);
    ivec1.push_back(3);
    ivec2.push_back(1);
    ivec2.push_back(2);
    ivec2.push_back(1);
    ivec2.push_back(4);

    cout << (ivec1 > ivec2) << endl; 

    return 0;
}
