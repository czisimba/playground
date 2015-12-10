#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string input;
    string total;

    while (cin >> input)
    {
        if (total.empty() == false)
            total = total + ' ' + input;
        else
            total = input;
    }
    cout << total << endl;

    return 0;
}
