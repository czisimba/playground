#include <iostream>

//using namespace::std;
template <typename T>
int compare(const T &v1,const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;

    return 0;
}

int main()
{
    int v1 = 1, v2 = 3;
    string s1("bbb"),s2("abb");

    cout << compare(v1,v2) << endl;
    cout << compare(s1,s2) << endl;

    return 0;
}
