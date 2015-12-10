#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

int main()
{
    map< string,vector<string> > jp;

    jp["cheng"].push_back("baozhu");
    jp["cheng"].push_back("jie");
    jp["cheng"].push_back("jianjun");
    jp["cheng"].push_back("hao");
    jp["cheng"].push_back("cai");
    jp["cheng"].push_back("zhi");

    map< string,vector<string> >::iterator iter = jp.find("cheng");
    for (vector<string>::iterator viter = iter->second.begin(); viter != iter->second.end(); ++viter)
    {
        cout << *viter << endl;
    }

    return 0;
}
