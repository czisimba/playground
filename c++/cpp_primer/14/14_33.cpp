#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class GT_cls {
public:
    GT_cls(const int b):bound(b) {
    }
    bool operator() (const int iv) {
        if (iv > bound)
            return 1;
        else 
            return 0;
    }
private:
    int bound;
};

int main()
{
    GT_cls gc(6);
    vector<int> iv;
    iv.push_back(1);
    iv.push_back(5);
    iv.push_back(8);
    iv.push_back(2);
    vector<int>::iterator iter;
    iter = find_if(iv.begin(), iv.end(), GT_cls(6));
    if (iter != iv.end())
        cout << *iter << endl;

    return 0;
}
