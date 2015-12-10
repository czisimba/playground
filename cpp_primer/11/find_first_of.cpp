#include <iostream>
#include <list>
#include <algorithm>

using namespace::std;

int main()
{
    list<int> phone_num, black_list;

    phone_num.push_back(1);
    phone_num.push_back(2);
    phone_num.push_back(3);
    phone_num.push_back(4);
    phone_num.push_back(5);

    black_list.push_back(3);
    black_list.push_back(4);

    list<int>::iterator iter = phone_num.begin();
    while ((iter = find_first_of(iter, phone_num.end(), black_list.begin(), black_list.end())) != phone_num.end())
    {
        cout << *iter << endl;
        ++iter;
    }

    return 0;
}
