#include <iostream>
#include <string>

using namespace::std;

class Account {
public:
    void year_end() {
        money += money * year_rate;
        //money += money * 0.1;
    }
    void show_account(ostream &os) {
        os << name << " " << money << endl;
    }
    Account(const string &nm, const double mn):name(nm),money(mn) {
    }
    /*
    static void set_year_rate(const double yr) {
        year_rate = yr;
    }
    */
private:
    string name;
    double money;
    static double year_rate;
};

int main()
{
    //Account::set_year_rate(0.1);
    Account cz("chengz", 10000);
    //cz.set_year_rate(0.1);
    cz.year_end();
    cz.show_account(cout);

    return 0;
}
