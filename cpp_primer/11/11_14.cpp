#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace::std;

int main()
{
    vector<int> ivec;
    list<int> ilist;

    for (int i = 0;i < 10;++i)
    {
        ivec.push_back(i);
    }

    //replace_copy(ivec.begin(), ivec.end(), back_inserter(ilist), 5, 100);
    //replace_copy(ivec.begin(), ivec.end(), front_inserter(ilist), 5, 100);
    replace_copy(ivec.begin(), ivec.end(), inserter(ilist, ilist.begin()), 5, 100);

    for (list<int>::iterator iter = ilist.begin(); iter != ilist.end();++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
