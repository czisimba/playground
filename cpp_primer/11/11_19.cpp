#include <iostream>
#include <algorithm>

using namespace::std;

int main()
{
    string s("FIRST,SECOND,LAST");
    //string sout(s.begin(), iter.base());
    string sout(s.rbegin(), s.rend());

    cout << sout << endl;

    return 0;
}
