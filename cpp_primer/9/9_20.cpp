#include <iostream>
#include <vector>
#include <list>

using namespace::std;

int cmp_vec_list(vector<int> &ivec, list<int> &ilist)
{
    vector<int>::const_iterator vec_iter = ivec.begin();
    list<int>::const_iterator list_iter = ilist.begin();
    for (;(vec_iter != ivec.end()) && (list_iter != ilist.end());
            ++vec_iter, ++list_iter)
    {
        if (*vec_iter != *list_iter)
            return -1;
    }
    if ((vec_iter != ivec.end()) || (list_iter != ilist.end()))
        return -1;
    else
        return 0;
}

int main()
{
    vector<int> ivec;
    list<int> ilist;
    int ret;
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    ilist.push_back(1);
    ilist.push_back(2);
    ilist.push_back(4);

    ret = cmp_vec_list(ivec, ilist);

    if (ret == -1)
        cout << "vector and list is different" << endl;
    else
        cout << "vector and list is same" << endl;
    return 0;
}
