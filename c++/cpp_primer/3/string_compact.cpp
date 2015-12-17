#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s_in;
    string s_out;
    string::size_type idx;

    cin >> s_in;
    for (idx = 0;idx != s_in.size() + 1;idx++)
        if (ispunct(s_in[idx]) == false)
            s_out += s_in[idx];
    cout << "string in  is " << s_in << endl;
    cout << "string out is " << s_out << endl;

    return 0;
}
