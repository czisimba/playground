#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec(100);
    
    ivec.push_back(0);
    cout << ivec.size() << endl;

    return 0;
}
