#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        if (true)
        {
            throw runtime_error("Must be error!");
        }
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
        cout << "only a test" << endl;
    }
    
    return 0;
}
