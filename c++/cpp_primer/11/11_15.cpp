#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace::std;

int main()
{
    int ia[10] = {1,2,3,4,100,5,100};
    list<int> ilist(ia, ia + 7);
    vector<int> ivec;

    for (list<int>::iterator iter = ilist.begin(); iter != ilist.end();++iter)
    {
        cout << *iter << endl;
    }
    cout << "list size:" << ilist.size() << endl;
    unique_copy(ilist.begin(), ilist.end(), back_inserter(ivec));

    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end();++iter)
    {
        cout << *iter << endl;
    }
    cout << "vector size:" << ilist.size() << endl;

    return 0;
}
