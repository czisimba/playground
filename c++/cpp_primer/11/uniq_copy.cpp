#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace::std;

int main()
{
    istream_iterator<int> i_in(cin), eos;
    vector<int> ivec(i_in, eos);

    ostream_iterator<int> i_out(cout, " ");
    sort(ivec.begin(), ivec.end());
    unique_copy(ivec.begin(), ivec.end(), i_out);

    return 0;
}
