#include <iostream>

using namespace::std;

template<class T,class U> class A {
public:
    A(const T ra, const T rb, const U rc):a(ra),b(rb),c(rc) {
    }
    T get_a() {
        return a;
    }
    U get_c();
private:
    T a;
    T b;
    U c;
};

template<class T, class U> U A<T, U>::get_c() {
    return c;
}

int main()
{
    A<int, string> ai(1,2,"haode");
    cout << ai.get_a() << endl;
    cout << ai.get_c() << endl;

    return 0;
}
