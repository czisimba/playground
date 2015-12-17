#include <iostream>
#include <fstream>
#include <string>

using namespace::std;
ifstream file("/.config");
class NoName {
    const string name;
    int ival;
    double *dptr;
    ifstream &ifs;
public:
    NoName():name("NoName"),ifs(file) {
    }
};

int main()
{
    NoName nn;
    return 0;
}
