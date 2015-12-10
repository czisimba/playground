#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace::std;

int main()
{
    list<int> ilist;
    vector<int> ivec;
    ilist.push_back(1);
    ilist.push_back(2);
    ilist.push_back(3);
    ilist.push_back(4);

    replace_copy(ilist.begin(), ilist.end(), back_inserter(ivec), 3, 5);
    for (list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
    {
        cout << *iter << endl;
    }
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
