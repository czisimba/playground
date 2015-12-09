#include <iostream>
#include <string>

using namespace::std;

class ScreenPtr {
public:
    ScreenPtr(int *const p):value(*p) {
    }
    int value;
private:
};

class NoName {
public:
    NoName(int *const p):ptr(new ScreenPtr(p)) {
    }
    ScreenPtr *operator->() {
        return ptr;
    }
    ScreenPtr &operator*() {
        return *ptr;
    }
private:
    ScreenPtr *ptr;
};

int main()
{
    int *ip = new int(100);
    NoName nm(ip);
    cout << nm->value << endl;
    cout << (*nm).value << endl;

    return 0;
}
