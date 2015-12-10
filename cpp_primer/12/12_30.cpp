#include <vector>

using namespace::std;

void f(const vector<int> & iv) {
}

int main()
{
    vector<int> iv;
    f(iv);
    f(42);

    return 0;
}
