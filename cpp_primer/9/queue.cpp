#include <iostream>
#include <queue>

using namespace::std;

int main()
{
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << que.front() << endl;
    cout << que.back() << endl;
    que.pop();
    cout << que.front() << endl;
    cout << que.back() << endl;

    return 0;
}
