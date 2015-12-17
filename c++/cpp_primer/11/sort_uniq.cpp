#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace::std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool GT6(const string &s)
{
    return s.size() >= 6;
}

int main()
{
    string s;
    vector<string> svec;

    while (cin >> s)
        svec.push_back(s);

    sort(svec.begin(), svec.end());
    vector<string>::iterator uniq_end = unique(svec.begin(), svec.end());
    svec.erase(uniq_end, svec.end());
    stable_sort(svec.begin(), svec.end(), isShorter);
    vector<string>::size_type wc = count_if(svec.begin(), svec.end(), GT6);
    for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "word over 6 is:" << wc << endl;

    return 0;
}
