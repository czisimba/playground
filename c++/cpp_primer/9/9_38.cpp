#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string search_str("ab2c3d7R4E6");
    string interger("1234567890");
    string abc;
    string::size_type pos = 0;

    for (char c = 'a'; c != 'z' + 1;c++)// init a-z
        abc.push_back(c);
    for (char c = 'A'; c != 'Z' + 1;c++)// init A-Z
        abc.push_back(c);

    cout << "interger:" << endl;
    while ((pos = search_str.find_first_of(interger, pos)) != string::npos)
    {
        cout << search_str[pos];
        pos++;
    }
    cout << endl;

    pos = 0;//reset pos
    cout << "abc:" << endl;
    while ((pos = search_str.find_first_of(abc, pos)) != string::npos)
    {
        cout << search_str[pos];
        pos++;
    }
    cout << endl;

    return 0;
}
