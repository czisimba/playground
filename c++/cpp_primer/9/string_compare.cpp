#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s1("chengzhi");
    string s2("zhi");
    char s3[100] = "zhi";

    cout << s1.compare(s2) << endl;
    cout << s1.compare(5, 3, s2) << endl;
    cout << s1.compare(6, 2, s2, 1, 2) << endl;
    cout << s1.compare(5, 3, s3) << endl;
    cout << s1.compare(6, 2, s3, 1, 2) << endl;

    return 0;
}
