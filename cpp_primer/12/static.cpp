#include <iostream>

using namespace::std;

class Account {
public:
    // interface function here
    void applyint() { amount += amount * interestRate;}
    static double rate();
    static void rate(double);
    Account(const string nm, const double am):owner(nm),amount(am) {
    }
    void show() {
        cout << owner << " " << amount << endl;
    }
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();

};
double Account::interestRate = initRate();
double Account::rate() { 
    return interestRate; 
}
void Account::rate(double r) {
    interestRate = r;
}// sets a new rate
double Account::initRate() {
    return 0;
}

int main()
{
    double rate;
    Account ac1("yx17", 10000);

    rate = Account::rate();
    cout << rate << endl;

    Account::rate(0.07);
    rate = Account::rate();
    cout << rate << endl;

    ac1.show();
    for (int i = 0;i < 30; ++i)
        ac1.applyint();
    ac1.show();

    return 0;
}
