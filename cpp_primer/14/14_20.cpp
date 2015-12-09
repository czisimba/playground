#include <iostream>
#include <string>

using namespace::std;

class Screen {
public:
    Screen(int *const p):value(*p) {
    }
private:
    int value;
};

class ScrPtr {
    friend class ScreenPtr;
public:
    ScrPtr(int *const p):sp(p),use(1) {
    }
    ~ScrPtr() {
        delete sp;
    }
private:
    int *sp;
    int use;
};

class ScreenPtr {
public:
    ScreenPtr(int *const p):ptr(new ScrPtr(p)) {
    }
    ScreenPtr(const ScreenPtr &orig) {// maybe orig is this
        ++orig.ptr->use;
        ptr = orig.ptr;
    }
    ScreenPtr &operator=(const ScreenPtr &orig) {
        ++orig.ptr->use;
        if (--ptr->use == 0)
            delete ptr;
        ptr = orig.ptr;
        return *this;
    }
    ~ScreenPtr() {
        if (--ptr->use == 0)
            delete ptr;
    }
private:
    ScrPtr *ptr;
};

int main()
{
    int *ip = new int(100);
    int *ip1 = new int(100);
    ScreenPtr sp(ip);
    ScreenPtr sp1(ip1);
    sp1 = sp;
    sp1 = sp1;

    return 0;
}
