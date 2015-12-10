#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s("chengzhi");
    string s1("zh");
    string s2;
    string::iterator iter = s.begin();
    string::iterator iter1 = s1.begin();
    string::size_type pos = 0;

    //s1 = s.substr();
    //s2 = s.replace(iter, iter + 5, iter1, iter1 + 4);
    pos = s.find("zd", 0, 2);

    cout << pos << endl;

    return 0;
}
