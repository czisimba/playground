#include <iostream>
#include <string>
#include <map>

using namespace::std;

int main()
{
    string word;
    map<string, int> dic;

    while (cin >> word)
    {
        pair<map<string, int>::iterator, bool> ret = dic.insert(make_pair(word, 1));
        if (ret.second == 0)
            ++ret.first->second;
    }

    for (map<string, int>::iterator iter = dic.begin(); iter != dic.end(); ++iter)
    {
        cout << iter->first << " :" << iter->second << endl;
    }

    return 0;
}
