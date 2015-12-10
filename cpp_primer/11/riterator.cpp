#include <iostream>
#include <algorithm>

using namespace::std;

int main()
{
    string s("FIRST,SECOND,LAST");
    string::reverse_iterator iter = find(s.rbegin(), s.rend(), ',');
    //string sout(s.begin(), iter.base());
    string sout(iter, s.rend());

    cout << sout << endl;

    return 0;
}
