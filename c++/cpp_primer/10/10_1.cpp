#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace::std;

int main()
{
    string s_in;
    int i_in;
    vector< pair<string, int> > v_pair;

    while (cin >> s_in >> i_in)
    {
        v_pair.push_back(make_pair(s_in, i_in));
    }

    for (vector< pair<string, int> >::iterator iter = v_pair.begin(); iter != v_pair.end(); ++iter)
    {
        cout << "key:" << iter->first << " value:" << iter->second << endl;
    }

    return 0;
}
