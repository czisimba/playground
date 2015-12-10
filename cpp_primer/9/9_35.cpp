#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s("ChengZhi");
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
    {
        if (*iter >= 'A' && *iter <= 'Z')
            s.erase(iter);
    }
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
