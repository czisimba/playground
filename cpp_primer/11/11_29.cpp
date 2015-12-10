#include <iostream>
#include <string>
#include <list>

using namespace::std;

int main()
{
    string s;
    list<string> slist;

    while (cin >> s)
        slist.push_back(s);

    slist.sort();
    slist.unique();
    for (list<string>::iterator iter = slist.begin(); iter != slist.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
