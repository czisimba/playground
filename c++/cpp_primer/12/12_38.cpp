#include <iostream>

using namespace::std;

class Foo {
public:
    Foo(int v):ival(v) {
    }
    int get_val() {
        return ival;
    }
private:
    int ival;
};

int main()
{
    Foo f(2015);
    cout << f.get_val() << endl;

    return 0;
}
