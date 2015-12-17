#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s("chengzhi");
    
    cout << s <<endl;
    s.erase(s.begin());
    cout << s <<endl;

    return 0;
}
