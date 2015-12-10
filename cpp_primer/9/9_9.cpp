#include <iostream>
#include <list>

using namespace::std;

int main()
{
    list<int> ilist;
    for (list<int>::size_type i = 0; i != 100;++i)
    {
        ilist.push_back(i);
    }

    for (list<int>::const_iterator iter = ilist.end(); iter-- != ilist.begin();)
    {
        cout << *iter << endl;
    }

    return 0;
}
