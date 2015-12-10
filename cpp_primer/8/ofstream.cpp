#include <fstream>

using namespace::std;

int main()
{
    ofstream ofs;

    ofs.open("out", ofstream::out | ofstream::app);
    ofs << "tianqibucuo" << endl;
    ofs.close();

    return 0;
}
