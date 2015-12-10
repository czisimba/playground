#include <iostream>
#include <string>

using namespace::std;

class NoName {
public:
    NoName(const NoName &obj) {
        i = obj.i;
        d = obj.d;
        pstring = new string(*obj.pstring);
        //pstring = obj.pstring;
    }
    NoName():pstring(new string) {
    }
    ~NoName() {
        delete pstring;
    }
    string *pstring;
    int i;
    double d;
private:
};

int main()
{
    NoName nm1;
    *nm1.pstring = "111";
    NoName nm2(nm1);
    *nm1.pstring= "222";
    cout << *nm2.pstring << endl;

    return 0;
}
