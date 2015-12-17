#include <fstream>

using namespace::std;

int main()
{
    ofstream out1, out2;
    //out1 = out2; // error: cannot assign stream objects
    // print function: parameter is copied
    ofstream print(ofstream);
    //out2 = print(out2); 
    return 0;
}
