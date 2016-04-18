#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue {
public:
    void push(T t)
    {
        s1.push(t);
        cout << "push:[" << t <<  "]" << endl;
    };
    void pop() 
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty())
        {
            cout << "pop:[" << s2.top() <<  "]" << endl;
            s2.pop();
        }
    };
private:
    stack<T> s1;
    stack<T> s2;
};

int main()
{
    MyQueue<int> MQ;
    MQ.push(1);
    MQ.push(2);
    MQ.pop();
    MQ.push(3);
    MQ.push(4);
    MQ.push(5);
    MQ.push(6);
    MQ.pop();
    MQ.pop();

    return 0;
}
