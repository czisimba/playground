#include <iostream>

using namespace::std;

class NoName {
public:
    NoName():val1(13),val2(10) {
    }
    NoName(const NoName &nm) {
        val2 = nm.val2;
    }
    void show_val() {
        cout << val1 << " " << val2 << endl;
    }
private:
    int val1;
    int val2;
};

int main()
{
    NoName obj = 13;

    obj.show_val();

    return 0;
}
