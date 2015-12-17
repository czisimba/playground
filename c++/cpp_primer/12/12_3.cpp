#include <iostream>
#include <string>
#include <utility>

using namespace::std;

class Person {
public:
    Person(const string &nm, const string &addr):name(nm), address(addr){ }
    pair<string, string> get_name_addr() const { 
        return make_pair(name, address);
    }
    string get_name() const { 
        return name;
    }
    string get_addr() const { 
        return address;
    }
    string name;
    string address;
};

int main()
{
    Person cz("cz", "xeq");
    //cz.name = "chengzhi";
    //cz.address = "xierqi";
    pair<string, string> name_addr = cz.get_name_addr();
    cout << name_addr.first << " " << name_addr.second << endl;
    cout << cz.get_name() << " " << cz.get_addr() << endl;

    return 0;
}
