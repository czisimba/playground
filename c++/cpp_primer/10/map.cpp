#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace::std;
typedef pair<string, int> Author;

int main()
{
    vector<Author> av;
    map<string, int> word_count;
    map<string ,int>::iterator it;

    av.push_back(make_pair("cz", 18));
    av.push_back(make_pair("cz", 25));
    av.push_back(make_pair("smq", 17));
    av.push_back(make_pair("mhd", 19));
    word_count.insert(av.begin(), av.end());
    for (map<string, int>::iterator map_it = word_count.begin();
            map_it != word_count.end();++map_it)
    {
        cout << "name:" << map_it->first << " age:" << map_it->second << endl;
    }
    it = word_count.find("smq");
    word_count.erase(it);
    it = word_count.find("smq");
    if (it != word_count.end())
        cout << "smq is exist!" << endl;
    else
        cout << "smq is not exist!" << endl;


    return 0;
}
