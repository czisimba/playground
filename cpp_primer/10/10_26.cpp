#include <iostream>
#include <map>
#include <set>

using namespace::std;

typedef multimap<string, string>::iterator map_it;

int main()
{
    multimap<string, string> phone_list;
    
    // init
    phone_list.insert(make_pair("cheng", "zhi"));
    phone_list.insert(make_pair("yan", "xian"));
    phone_list.insert(make_pair("yan", "ming"));
    phone_list.insert(make_pair("cheng", "cai"));

    pair<map_it, map_it> pos = phone_list.equal_range("cheng");

    if (pos.first != pos.second)
        phone_list.erase("cheng");

    pos = phone_list.equal_range("cheng");
    while (pos.first != pos.second)
    {
        cout << pos.first->first << pos.first->second << endl;
        ++pos.first;
    }

    return 0;
}
