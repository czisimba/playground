#include <iostream>
#include <sstream>

using namespace::std;

int main()
{
    ostringstream format_message;
    int val1 = 512,val2 = 1024;

    format_message << "val1: " << val1 << "\n"
                    << "val2: " << val2 << "\n";

    istringstream istream(format_message.str());
    string dump;
    int val3 , val4;
    cout << istream.str();
    istream >> dump >> val3 >> dump >> val4;
    cout << "dump:" << dump << " val3:" << val3 << " val4:" << val4 << endl;

    return 0;
}
