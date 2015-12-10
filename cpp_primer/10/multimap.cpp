#include <iostream>
#include <map>
#include <set>

using namespace::std;

int main()
{
    multimap<string, string> phone_list;
    
    // init
    phone_list.insert(make_pair("cheng", "zhi"));
    phone_list.insert(make_pair("yan", "xian"));
    phone_list.insert(make_pair("yan", "ming"));
    phone_list.insert(make_pair("cheng", "cai"));

    multimap<string, string>::iterator beg = phone_list.lower_bound("cheng"),
        end = phone_list.upper_bound("cheng");

    for (multimap<string, string>::iterator iter = beg; iter != end; ++iter)
    {
        cout << iter->first << iter->second << endl;
    }

    return 0;
}
