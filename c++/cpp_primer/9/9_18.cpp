#include <iostream>
#include <bitset>
#include <list>
#include <deque>

using namespace::std;

int main()
{
    list<int> ilist;
    for (list<int>::size_type i = 0; i != 100; ++i)
    {
        ilist.push_back(i);
    }

    bitset<1> b = 0;
    deque<int> ideq1;
    deque<int> ideq2;
    /*idx: 0 1 2 3 4 5
     * b : 0 1 0 1 0 1
     */
    for (list<int>::const_iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
    {
        if (b == 0)
            ideq1.push_back(*iter);
        else
            ideq2.push_back(*iter);
        b ^= 1;
    }

    for (deque<int>::const_iterator iter = ideq1.begin(); iter != ideq1.end(); ++iter)
    {
        cout << *iter << endl;
    }
    for (deque<int>::const_iterator iter = ideq2.begin(); iter != ideq2.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
