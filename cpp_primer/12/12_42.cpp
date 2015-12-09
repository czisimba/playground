#include <vector>

using namespace::std;

class Example {
    static double rate;
    static const int vecSize = 20;
    static vector<double> vec;
};

double Example::rate = 6.5;
vector<double> Example::vec(vecSize);

int main()
{
    return 0;
}
