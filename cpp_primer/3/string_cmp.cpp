#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1, str2;
    string::size_type s1_len,s2_len;

    cin >> str1;
    cin >> str2;
    s1_len = str1.size();
    s2_len = str2.size();
    cout << "str1 and str2' length is " << (s1_len == s2_len ? "same" : "different") << endl; 
    if (s1_len != s2_len)
        cout << "str1 and str2 long string is " << (s1_len > s2_len ? str1 : str2) << endl; 

    return 1;
}
