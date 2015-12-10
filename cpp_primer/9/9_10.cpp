#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace::std;

int main()
{
    const vector<int> ivec(10);
    vector<string> svec(10);
    list<int> ilist(10);

    //vector<int>::iterator it = ivec.begin();
    //list<int>::iterator it1 = ilist.begin() + 2;
    vector<string>::iterator it1 = svec.begin();
    vector<string>::iterator it2 = svec.end();
    cout << "begin:" << *it1 << endl;
    //cout << "end:" << it2 << endl;
    //for (vector<list>::iterator it3 = svec.begin(); it3 != 0;++it3)
    {
        //...
    }

    return 0;
}
