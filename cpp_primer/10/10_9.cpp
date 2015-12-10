#include <iostream>
#include <string>
#include <map>

using namespace::std;

int main()
{
    string word;
    map<string, int> dic;

    while (cin >> word)
        ++dic[word];

    for (map<string, int>::iterator iter = dic.begin(); iter != dic.end(); ++iter)
    {
        cout << iter->first << " :" << iter->second << endl;
    }

    return 0;
}
