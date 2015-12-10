#include <iostream>
#include <iterator>
#include <vector>

using namespace::std;

int main()
{
    istream_iterator<string> s_in(cin), eos; 
    vector<string> svec(s_in, eos);

    for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
