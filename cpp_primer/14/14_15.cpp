#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

class CheckoutRecord {
public:
    CheckoutRecord &operator=(CheckoutRecord &);
private:
    double book_id;
    string title;
    pair<string, string> borrower;
    vector< pair<string, string>* > wait_list;
};
CheckoutRecord &CheckoutRecord::operator=(CheckoutRecord &orig) {
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


int main()
{
    CheckoutRecord cr1, cr2;
    cr2 = cr1;

    return 0;
}
