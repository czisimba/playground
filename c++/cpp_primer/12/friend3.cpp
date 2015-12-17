#include <iostream>
#include <string>

using namespace::std;
class Girl;

class Boy {
public:
    void display(Girl &);
};

class Girl {
    friend void Boy::display(Girl &);
public:
    Girl(const string &nm, const int ag):name(nm),age(ag) {
    }
private:
    string name;
    int age;
};

void Boy::display(Girl &g) {
    cout << g.name << " " << g.age << endl;
}


int main()
{
    Girl yx17("yanxian", 25);
    Boy cz;

    cz.display(yx17);

    return 0;
}
