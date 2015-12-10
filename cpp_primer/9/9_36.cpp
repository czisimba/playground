#include <iostream>
#include <vector>
#include <string>

using namespace::std;

int main()
{
    vector<char> cvec;
    cvec.push_back('c');
    cvec.push_back('z');
    string s;
    for (vector<char>::iterator iter = cvec.begin(); iter != cvec.end(); ++iter)
    {
        s += *iter;
    }
    cout << s << endl;
    return 0;
}
