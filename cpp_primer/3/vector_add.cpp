#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int input;
    vector<int> iv;

    while (cin >> input)
    {
        iv.push_back(input);
        if ((iv.size() & 0x1) == 0)
        {
            cout << "iv cnt: " << iv.size() - 1 << " and " << iv.size() 
                << " sum value is "<< iv[iv.size() - 2] + iv[iv.size() - 1] << endl;
        }
    }

    cout << "iv total cnt is: " << iv.size();
    if ((iv.size() & 0x1) == 1)
    {
        cout << " is odd,last value is: " << iv[iv.size() - 1] << endl;
    }

    return 0;
}
