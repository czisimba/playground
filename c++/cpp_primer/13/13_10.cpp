#include <iostream>
#include <string>

using namespace::std;

class Emplyee {
public:
    Emplyee(const string &nm = "nobody"):name(nm),id(next_id) {
        ++next_id;
    }
    Emplyee(const Emplyee &em):name(em.name),id(next_id) {
        ++next_id;
    }
    Emplyee &operator=(const Emplyee &em) {
        name = em.name;
        id = em.id;
        ++next_id;
        return *this;
    }
    string name;
    int id;
private:
    static int next_id;
};
int Emplyee::next_id = 0;

int main()
{
    Emplyee cz("chengzhi");
    Emplyee cz1(cz);
    Emplyee cz2 = cz;
    cout << cz.id << endl;
    cout << cz1.id << endl;
    cout << cz2.id << endl;

    return 0;
}
