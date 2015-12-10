#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace::std;

int main()
{
    list<int> ilist;
    for (list<int>::size_type i = 0;i != 100; ++i)
    {
        ilist.insert(ilist.end(), i);
    }

    for (list<int>::const_reverse_iterator iter = ilist.rbegin(); iter != ilist.rend(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
