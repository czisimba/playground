#include <string>

using namespace::std;

class NoName {
    string *pstring;
    int ival;
    double dval;
public:
    NoName(string *ps = NULL, int iv = 0, double dv = 0.0):pstring(ps),ival(iv),dval(dv) {
    }
};

int main()
{
    NoName n1;
    NoName n2(NULL);
    NoName n3(NULL, 1);
    NoName n4(NULL, 1, 3.0);

    return 0;
}
