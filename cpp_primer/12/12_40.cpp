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
    Foo &FooVal() {
        ++get_sf_count;
        return sf;
    }
    int callsFoolVal() {
        return get_sf_count;
    }
private:
    static int sival;
    static Foo sf;
    static int get_sf_count;
};
int Bar::sival = 0;
Foo Bar::sf = 2015;
int Bar::get_sf_count = 0;

int main()
{
    Foo f(2015);
    cout << f.get_val() << endl;
    Bar b;
    b.FooVal();
    b.FooVal();
    b.FooVal();
    b.FooVal();
    b.FooVal();
    b.FooVal();
    cout << b.callsFoolVal() << endl;

    return 0;
}
