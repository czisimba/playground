#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

class CheckoutRecord {
public:
    CheckoutRecord &operator=(const CheckoutRecord &);
    CheckoutRecord &operator=(const pair<string, string> *);
private:
    double book_id;
    string title;
    pair<string, string> borrower;
    vector< pair<string, string>* > wait_list;
};
CheckoutRecord &CheckoutRecord::operator=(const CheckoutRecord &orig) {
    book_id = orig.book_id;
    title = orig.title;
    borrower = orig.borrower;
    for (vector< pair<string, string>* >::const_iterator iter = wait_list.begin(); iter != wait_list.end(); ++iter)
    {
        //pair<string, string> *pp = new pair<string, string>;
        //*pp = **iter;
        wait_list.push_back(new pair<string, string>(**iter));//not easy to read
    }
}
CheckoutRecord &CheckoutRecord::operator=(const pair<string, string> *new_waiter)
{
    wait_list.push_back(new pair<string, string>(*new_waiter));//not easy to read
}


int main()
{
    CheckoutRecord cr1, cr2;
    string name("chengz");
    string zy("txgc");
    cr2 = cr1;
    cr2 = &make_pair(name, zy);

    return 0;
}
