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
    copy(ivec.begin(), ivec.end(), front_inserter(ilist)); // cant use push_front on list

    
    return 0;
}
