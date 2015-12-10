#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s("chengzhi");
    string s1("yanxian");
    char arr[20] = "yanxian";

    //s.insert(0, arr + 3, 7);
    //s.assign(arr);
    s.erase(0, 5);

    cout << s << endl;

    return 0;
}
