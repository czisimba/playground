#include <iostream>
#include <string>

using namespace::std;

class Girl {
    friend class Boy; 
public:
    Girl(const string &n, const int ag):name(n),age(ag) {
    }
private:
    string name;
    int age;
};

class Boy {
public:
    void display(Girl &);
};

void Boy::display(Girl &g)
{
    cout << g.name << " " << g.age << endl;
}


int main()
{
    Girl yx17("yanxian",25);
    Boy cz;
    cz.display(yx17);

    return 0;
}
