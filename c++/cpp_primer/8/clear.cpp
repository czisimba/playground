#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace::std;

int main()
{
    vector<string> books_name;
    ifstream in_file;

    books_name.push_back("1");
    books_name.push_back("2");
    books_name.push_back("3");
    books_name.push_back("4");
    books_name.push_back("5");
    books_name.push_back("6");
    vector<string>::const_iterator iter = books_name.begin();

    while (iter != books_name.end())// check vector is empty
    {
        in_file.open(*iter);
        if (in_file)
        {
            cout << "open file:" << *iter << " success" << endl;
            cout << "processing file:" << *iter << "..." << endl; // simulate processing
            usleep(500 * 1000);
            cout << "processing file:" << *iter << " done" << endl;
        }
        else
        {
            cout << "open file:" << *iter << " fail" << endl;
        }
        in_file.close();
        in_file.clear(); // clear old fstream state
        iter++;
    }

    return 0;
}
