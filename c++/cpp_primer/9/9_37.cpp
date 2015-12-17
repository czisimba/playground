#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string input;
    string s;
    cout << s.size() << endl;
    s.resize(128);
    cout << s.size() << endl;
    while (cin >> input)
        s += input;

    return 0;
}
