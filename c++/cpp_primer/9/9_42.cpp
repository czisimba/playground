#include <iostream>
#include <stack>

using namespace::std;

int main()
{
    string word;
    stack<string> s_stk;

    while (cin >> word)//get words
    {
        s_stk.push(word);
    }

    while (s_stk.size() != 0)// pop all words to teriminal
    {
        cout << s_stk.top() << endl;
        s_stk.pop();
    }

    return 0;
}
