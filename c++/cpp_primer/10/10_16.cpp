#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

int main()
{
    vector<int> ivec;
    map< string, vector<int> > dic;
    map< string, vector<int> >::iterator iter;

    ivec.push_back(0);
    ivec.push_back(1);
    dic.insert(make_pair("cz", ivec));
    dic.erase(dic.begin(), dic.end());
    iter = dic.find("cz");
    if (iter != dic.end())
        cout << iter->second.size() << endl;
    else
        cout << "cant't find cz in the dic" << endl;

    return 0;
}
