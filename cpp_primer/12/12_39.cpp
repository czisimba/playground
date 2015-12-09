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

class Bar {
public:
    static int sival;
    static Foo sf;
private:
};
int Bar::sival = 0;
Foo Bar::sf = 2015;

int main()
{
    Foo f(2015);
    cout << f.get_val() << endl;
    Bar b;
    cout << b.sf.get_val() << endl;

    return 0;
}
