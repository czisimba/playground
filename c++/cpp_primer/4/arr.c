#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define ARRAY_SIZE 10
int main()
{
    string input;
    int idx;
    char arr[ARRAY_SIZE];

    cin >> input;
    for (idx = 0;idx != input.size();++idx)
        arr[idx] = input[idx];
    arr[idx] = '\0';

    cout << arr << endl;

    return 0;
}
