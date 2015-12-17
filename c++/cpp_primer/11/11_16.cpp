#include <iostream>
#include <fstream>
#include <vector>

using namespace::std;

int main()
{
    ifstream src_file("./11_16.cpp");
    istream_iterator<string> s_in(src_file),eof;
    ostream_iterator<string> s_out(cout, " ");

    copy(s_in, eof , s_out);
    src_file.close();

    return 0;
}
