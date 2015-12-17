#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

int main()
{
    string word;
    map< string, vector<int> > dic;

    while (cin >> word)
    {
        pair< map<string, vector<int> >::iterator, bool> ret = dic.insert(make_pair(word, 1));
    }

    for (map< string, vector<int> >::iterator iter = dic.begin(); iter != dic.end(); ++iter)
    {
        //cout << iter->first << " :" << iter->second << endl;
    }

    return 0;
}
