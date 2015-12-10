#include <iostream>
#include <fstream>

using namespace::std;

int main()
{
    ifstream infile;
    ofstream outfile;
    string word;

    infile.open("copy.cpp");
    if (!infile)
    {
        cerr << "error,open infile fail" << infile << endl;
        return -1;
    }
    outfile.open("out");
    if (!outfile)
    {
        cerr << "error,open outfile fail" << outfile << endl;
        return -1;
    }
    while (infile >> word)
        outfile << word << endl;

    infile.close();
    outfile.close();

    return 0;
}
