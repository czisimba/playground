#include <iostream>
#include <list>
#include <algorithm>

using namespace::std;

int main()
{
    int ia[] = {0,1,2,3,4,0,8,9};
    list<int> ilist(ia, ia + 8);
    list<int>::reverse_iterator iter = find(ilist.rbegin(), ilist.rend(), 0);

    cout << *iter << endl;

    return 0;
}
