#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace::std;

int main()
{
    istream_iterator<int> i_in(cin), eos;
    ofstream odd_file("./odd"),even_file("./even");
    ostream_iterator<int> odds(odd_file, " "), evens(even_file, "\n");

    while (i_in != eos)
    {
        if ((*i_in & 1) == 1)
            *odds++ = *i_in++;
        else
            *evens++ = *i_in++;
    }

    return 0;
}
