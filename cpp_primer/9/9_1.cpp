#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace::std;

int main()
{
    int ia[7] = {1, 2, 3, 8, 9, 11, 28};
    string sa[6] = {"Fort sumter", "cz" , "mhd", "smq", "yx", "lw"};
    vector<string> svec(sa, sa + 6);// ok
    list<int> ilist(ia + 4, ia + 6);// ok
    vector<int> ivec(ia, ia + 50); // error, vector overflow
    list<string> slist(sa + 6, sa);// error, program be killed
    for (list<string>::const_iterator iter = slist.begin(); iter != slist.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
