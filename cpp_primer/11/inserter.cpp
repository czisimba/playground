#include <iostream>
#include <vector>
#include <list>

using namespace::std;

int main()
{
    vector<int> ivec;
    list<int> ilist;
    ilist.push_back(11);

    //copy(ilist.begin(), ilist.end(), front_inserter(ivec)); // cant't use push_front on vector
    copy(ivec.begin(), ivec.end(), inserter(ilist, ilist.begin())); // cant use push_front on list

    for (list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
    {
        cout << *iter << endl;
    }
    
    return 0;
}
