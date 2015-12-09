#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class GT_cls {
public:
    GT_cls(const int l, const int h):len_low(l),len_high(h) {
    }
    bool operator() (const string &s) {
        if (s.size() >= len_low && s.size() <= len_high)
            return 1;
        else 
            return 0;
    }
private:
    int len_low;
    int len_high;
};

int main()
{
    vector<string> iv;
    iv.push_back("12345678901234");
    iv.push_back("123456789");
    iv.push_back("1234");
    iv.push_back("");
    int cnt = count_if(iv.begin(), iv.end(), GT_cls(1,10));
    cout << cnt << endl;

    return 0;
}
