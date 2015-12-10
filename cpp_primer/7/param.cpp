#include <iostream>
using namespace std;

void swap(int &v1, int &v2)
{
    int tmp;
    tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int main()
{
    int v1 = 10, v2 = 0;

    cout << "before swap v1:" << v1 << "v2:" << v2 << endl;
    swap(v1,v2);
    cout << "after  swap v1:" << v1 << "v2:" << v2 << endl;


    return 0;
}
