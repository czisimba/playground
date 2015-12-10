#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s("chengzhi");
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
    {
        *iter = toupper(*iter);
        cout << *iter << endl;
    }
    return 0;
}
