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
    int cnt = 0;

    while (cin >> input)
    {
        upper = "";
        for (string::size_type idx = 0; idx != input.size(); idx++)
            upper += toupper(input[idx]);
        sv.push_back(upper);
    }

    cout << " word list(total word: " << sv.size() << " ):" << endl;
    for (vector<string>::size_type idx1; idx1 != sv.size(); idx1++)
    {
        cout << sv[idx1] << " ";
        if (((idx1 + 1) % BREAK_LINE_NUM  == 0) || idx1 == sv.size() - 1)
            cout << endl;
    }

    return 0;
}
