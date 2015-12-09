#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class GT_cls {
public:
    GT_cls(const int v):val(v) {
    }
    bool operator() (const int iv) {
        if (iv == val)
            return 1;
        else 
            return 0;
    }
private:
    int val;
};

int main()
{
    vector<int> iv;
    iv.push_back(1);
    iv.push_back(5);
    iv.push_back(8);
    iv.push_back(2);
    replace_if(iv.begin(), iv.end(), GT_cls(8), 10);
    ;
    for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
