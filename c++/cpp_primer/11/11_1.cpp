#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
    int mark;
    vector<int> mark_list;

    while (cin >> mark)
        mark_list.push_back(mark);

    cout << count(mark_list.begin(), mark_list.end(), 100) << endl;

    return 0;
}
