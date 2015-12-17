#include <iostream>
#include <stack>

using namespace::std;

int main()
{
    stack<int> stk;
    //int i = 1 == 1 ? 1 : 0;
    cout << ((stk.empty() == true) ? 0 : stk.top()) << endl;
    stk.push(1);
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;

    return 0;
}
