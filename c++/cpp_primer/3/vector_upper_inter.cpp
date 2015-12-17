#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define BREAK_LINE_NUM 8
int main()
{
    string input;
    string upper;
    vector<string> sv;
    vector<string>::size_type cnt = 0;

    while (cin >> input)
    {
        upper = "";
        for (string::size_type idx = 0; idx != input.size(); idx++)
            upper += toupper(input[idx]);
        sv.push_back(upper);
    }

    cout << " word list(total word: " << sv.size() << " ):" << endl;
    for (vector<string>::iterator iter = sv.begin(); iter != sv.end(); iter++)
    {
        cnt++;
        cout << *iter << " ";
        if ((cnt % BREAK_LINE_NUM  == 0) || cnt == sv.size())
            cout << endl;
    }

    return 0;
}
