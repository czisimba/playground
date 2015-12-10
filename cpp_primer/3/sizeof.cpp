#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    cout << "sizeof [int] is " << sizeof(int) << endl;
    cout << "sizeof [string::size_type] is " << sizeof(string::size_type) << endl;
    cout << "sizeof [vector<bool>] is " << sizeof(vector<bool>::size_type) << endl;
    cout << "sizeof [vector<char>] is " << sizeof(vector<char>::size_type) << endl;
    cout << "sizeof [size_t] is " << sizeof(size_t) << endl;
    return 0;
}
