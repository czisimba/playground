#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
    vector<int> ivec1,ivec2;
    ivec1.push_back(1);
    ivec2.push_back(2);

    cout << "ivec1[0]:" << ivec1[0] << endl;
    cout << "ivec2[0]:" << ivec2[0] << endl;
    ivec1.swap(ivec2);
    cout << "after swap:" << endl;
    cout << "ivec1[0]:" << ivec1[0] << endl;
    cout << "ivec2[0]:" << ivec2[0] << endl;
    ivec1 = ivec2;
    cout << "ivec2 to ivec1:" << endl;
    cout << "ivec1[0]:" << ivec1[0] << endl;
    cout << "ivec2[0]:" << ivec2[0] << endl;
    ivec2.assign(1, 100);
    cout << "ivec2 assign:" << endl;
    cout << "ivec1[0]:" << ivec1[0] << endl;
    cout << "ivec2[0]:" << ivec2[0] << endl;


    return 0;
}
