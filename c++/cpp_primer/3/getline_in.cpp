#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string word;

    while (getline(cin,word))
        cout << word << endl;

    return 1;
}
