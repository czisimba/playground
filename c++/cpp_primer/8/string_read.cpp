#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace::std;

int main()
{
    ifstream in_file("clear.cpp");
    vector<string> svec;
    string in_line;

    while (getline(in_file, in_line))
    {
        svec.push_back(in_line);
    }

    for (vector<string>::const_iterator iter = svec.begin();iter != svec.end();++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
