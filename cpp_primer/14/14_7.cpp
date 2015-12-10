#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

class CheckoutRecord {
    friend ostream &operator<<(ostream &, CheckoutRecord &);
public:
private:
    double book_id;
    string title;
    pair<string, string> borrower;
    vector< pair<string, string>* > wait_list;
};

ostream &operator<<(ostream &os, CheckoutRecord &cr)
{
    os << cr.book_id << "\t" << cr.title << "\t" << "(" << cr.borrower.first << "\t" << cr.borrower.second << ")\t";
    for (vector< pair<string, string>* >::const_iterator iter = cr.wait_list.begin(); iter != cr.wait_list.end(); ++iter)
    {
        cout << "(" << (*iter)->first << "," << (*iter)->second << ")" << endl;
    }
    return os;
}

int main()
{
    CheckoutRecord cr;
    cout << cr;

    return 0;
}
