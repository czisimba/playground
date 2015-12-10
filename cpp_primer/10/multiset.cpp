#include <iostream>
#include <map>
#include <set>

using namespace::std;

int main()
{
    multiset<string> phone_list;
    
    // init
    phone_list.insert("cheng");
    phone_list.insert("yan");
    phone_list.insert("yan");
    phone_list.insert("cheng");

    multiset<string>::iterator beg = phone_list.lower_bound("cheng"),
        end = phone_list.upper_bound("cheng");

    for (multiset<string>::iterator iter = beg; iter != end; ++iter)
    {
/bin/bash: :wqa: command not found
    }

    return 0;
}
