#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string word;

    cin >> word;
    cout << isdigit(word[0]);

    return 1;
}
