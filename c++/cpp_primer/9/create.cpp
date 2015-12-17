#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace::std;

int main()
{
    vector<int> high;
    high.push_back(173);
    high.push_back(169);
    high.push_back(185);

    //deque<int> lhigh(high.begin(), high.end());
    deque<int> lhigh(10, 100);

    for (deque<int>::const_iterator iter = lhigh.begin(); iter != lhigh.end();++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
