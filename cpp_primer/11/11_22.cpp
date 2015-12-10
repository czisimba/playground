#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace::std;

int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> ivec(ia, ia + 10);
    list<int> ilist;
    copy(ivec.begin() + 2, ivec.end() - 2, front_inserter(ilist));

    for (list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
