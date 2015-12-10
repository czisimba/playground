#include <iostream>
#include <vector>
#include <map>

using namespace::std;

int main()
{
    map<string ,string> staff;
    staff.insert(make_pair("001", "cz"));
    staff.insert(make_pair("002", "mhd"));
    staff.insert(make_pair("003", "smq"));
    staff.insert(make_pair("004", "smq"));

    for (map<string, string>::iterator iter = staff.begin(); iter != staff.end(); ++iter)
    {
        if (iter->second == "smq")
            cout << iter->first << endl;
    }

    return 0;
}
