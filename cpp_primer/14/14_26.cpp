#include <iostream>
#include <string>
#include <stdexcept>

using namespace::std;

class CheckedPtr {
friend bool operator==(const CheckedPtr &lhs, const CheckedPtr &rhs);
friend bool operator!=(const CheckedPtr &lhs, const CheckedPtr &rhs);
friend bool operator<(const CheckedPtr &lhs, const CheckedPtr &rhs);
friend bool operator<=(const CheckedPtr &lhs, const CheckedPtr &rhs);
friend bool operator>(const CheckedPtr &lhs, const CheckedPtr &rhs);
friend bool operator>=(const CheckedPtr &lhs, const CheckedPtr &rhs);
friend CheckedPtr operator+(const CheckedPtr &lhs, size_t);
public:
    CheckedPtr(int *b, int *e):beg(b),end(e),curr(b) {
    }
    CheckedPtr& operator++();
    CheckedPtr& operator--();
    CheckedPtr& operator++(int);
    CheckedPtr& operator--(int);
    int& operator*() {
        if (beg == end)
            throw out_of_range("current pointer invalid");
        return *curr;
    }
    int& operator[](size_t idx) {
        if (beg + idx >= end || beg + idx < beg)
            throw out_of_range("index past the end of CheckedPtr");
        return *(beg + idx);
    }
    int* beg;
    int* end;
    int* curr;
private:
};

CheckedPtr& CheckedPtr::operator++() {
    if (curr == end)
        throw out_of_range("increment past the end of CheckedPtr");
    ++curr;
    return *this;
}
CheckedPtr& CheckedPtr::operator--() {
    if (curr == beg)
        throw out_of_range("decrement past the beg of CheckedPtr");
    --curr;
    return *this;
}
CheckedPtr& CheckedPtr::operator++(int) {
    // no check need here,the call to prefix increment will do the check
    CheckedPtr cp(*this);
    ++*this;
    return *this;
}
CheckedPtr& CheckedPtr::operator--(int) {
    // no check need here,the call to prefix decrement will do the check
    CheckedPtr cp(*this);
    --*this;
    return *this;
}

bool operator==(const CheckedPtr &lhs, const CheckedPtr &rhs) {
    return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr == rhs.curr;
}
bool operator!=(const CheckedPtr &lhs, const CheckedPtr &rhs) {
    return !(lhs == rhs);
}
bool operator<(const CheckedPtr &lhs, const CheckedPtr &rhs) {
    return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr < rhs.curr;
}
bool operator<=(const CheckedPtr &lhs, const CheckedPtr &rhs) {
    return !(lhs > rhs);
}
bool operator>(const CheckedPtr &lhs, const CheckedPtr &rhs) {
    return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr > rhs.curr;
}
bool operator>=(const CheckedPtr &lhs, const CheckedPtr &rhs) {
    return !(lhs < rhs);
}
CheckedPtr operator+(const CheckedPtr &lhs, size_t n) {
    CheckedPtr temp(lhs);
    temp.curr += n;
    if (temp.curr > temp.end)
        throw out_of_range("add past the beg of CheckedPtr");
    return temp;
}

int main()
{
    int ia[10] = {0,1,2,3,4,5,6,7,8,9};
    CheckedPtr cp(ia, ia + 8);
    cout << *cp.curr << endl;
    ++cp;
    cout << *cp.curr << endl;
    cp++;
    cout << *cp.curr << endl;
    --cp;
    cout << *cp.curr << endl;
    cp--;
    cout << *cp.curr << endl;
    cout << *cp << endl;
    cout << cp[0] << endl;
    cout << cp[4] << endl;
    cout << cp[7] << endl;
    //cout << cp[8] << endl;
    CheckedPtr cp1(ia, ia + 8);
    cp1++;
    cout << (cp == cp1) << endl;
    cout << (cp < cp1) << endl;
    CheckedPtr cp2(cp + 1);
    cout << (cp1 == cp2) << endl;
    cout << (cp == cp1) << endl;

    return 0;
}
