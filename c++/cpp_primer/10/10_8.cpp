#include <iostream>
#include <string>
#include <map>

using namespace::std;

int main()
{
    map<string, int> s_map;
    s_map.insert(make_pair("cz", 173));
    s_map.insert(make_pair("smq", 175));
    s_map.insert(make_pair("mhd", 172));
    s_map["zjh"] = 188;

    for (map<string, int>::iterator iter = s_map.begin(); iter != s_map.end(); ++iter)
    {
        if (iter->first == "cz")
            iter->second = 172;
        cout << iter->first << ": " << iter->second << endl;
    }

    return 0;
}
