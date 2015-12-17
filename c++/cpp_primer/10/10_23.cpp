#include <iostream>
#include <vector>

using namespace::std;

int main()
{
    string input;
    vector<string> exclude;

    while (cin >> input)
    {
        int find_flag = 0;
        for (vector<string>::iterator iter = exclude.begin(); iter != exclude.end(); ++iter)
        {
            if (*iter == input)
            {
                find_flag = 1; 
                break;
            }
        }
        if (find_flag == 0)
            exclude.push_back(input);
    }

    for (vector<string>::iterator iter = exclude.begin(); iter != exclude.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
