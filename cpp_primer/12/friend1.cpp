#include <iostream>

using namespace::std;

class INTEGER {
    int val;
    friend void Print (const INTEGER &obj);
public:
    INTEGER(const int v):val(v) {
    }

};

void Print (const INTEGER &obj)
{
    cout << obj.val << endl;
}

int main()
{
    INTEGER it(100);
    Print(it);

    return 0;
}
