#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

int main()
{
    map< string,vector< pair<string, string> > > jp;

    jp["cheng"].push_back(make_pair("baozhu", "1975"));
    jp["cheng"].push_back(make_pair("jie", "1979"));
    jp["cheng"].push_back(make_pair("jianjun", "1981"));
    jp["cheng"].push_back(make_pair("hao", "1983"));
    jp["cheng"].push_back(make_pair("cai", "1987"));
    jp["cheng"].push_back(make_pair("zhi", "1988"));

    map< string,vector< pair<string, string> > >::iterator iter = jp.find("cheng");
    for (vector< pair<string, string> >::iterator viter = iter->second.begin(); viter != iter->second.end(); ++viter)
    {
        cout << viter->first << " " << viter->second << endl;
    }

    return 0;
}
