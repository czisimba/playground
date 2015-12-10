#include <iostream>
#include <stack>

using namespace::std;

int main()
{
    string exp;
    stack<char> cstack;

    cout << "Please enter an expression:" << endl;
    cin >> exp;

    string::iterator iter = exp.begin();
    while (iter != exp.end())
    {
        if (*iter != ')')
        {
            cstack.push(*iter);
        }
        else
        {
            while (cstack.top() != '(' && cstack.empty() == 0)
            {
                cout << cstack.top() << endl;
                cstack.pop();
            }

            if (cstack.empty() == 1)
            {
                cout << "expression not match!" << endl;
            }
            else
            {
                cstack.pop();
                cstack.push('@');
            }
        }
        ++iter;
    } 

    return 0;
}
