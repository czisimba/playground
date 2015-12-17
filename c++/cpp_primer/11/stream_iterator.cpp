#include <iostream>
#include <iterator>

using namespace::std;

int main()
{
    istream_iterator<string> s_in(cin),eof;
    ostream_iterator<string> s_out(cout);

    while (s_in != eof)
    {
        *s_out++ = *s_in++;
    }

    return 0;
}
