#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string search_str("ab24c3d7R4E6");
    string interger("1234567890");
    string abc;
    string::size_type pos = 0, pos_new = 0;

    for (char c = 'a'; c != 'z' + 1;c++)// init a-z
        abc.push_back(c);
    for (char c = 'A'; c != 'Z' + 1;c++)// init A-Z
        abc.push_back(c);

    cout << "interger:" << endl;
    while ((pos_new = search_str.find_first_not_of(interger, pos)) != string::npos)
    {
        if (pos_new == pos)
        {
            pos_new++;
        }
        else
        {
            for (string::size_type st = pos; st != pos_new;++st)
                cout << search_str[st];
        }
        pos = pos_new;
    }
    cout << endl;

    pos = 0;//reset pos
    cout << "abc:" << endl;
    while ((pos_new = search_str.find_first_not_of(abc, pos)) != string::npos)
    {
        if (pos_new == pos)
        {
            pos_new++;
        }
        else
        {
            for (string::size_type st = pos; st != pos_new;++st)
                cout << search_str[st];
        }
        pos = pos_new;
    }
    cout << endl;

    return 0;
}
