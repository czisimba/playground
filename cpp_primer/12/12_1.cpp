#include <iostream>
#include <string>

using namespace::std;

class Person {
public:
    Person(const string &nm, const string &addr):name(nm), address(addr){ }
    string name;
    string address;
};

int main()
{
    Person cz("cz", "xeq");
    //cz.name = "chengzhi";
    //cz.address = "xierqi";
    cout << cz.name << " " << cz.address << endl;

    return 0;
}
