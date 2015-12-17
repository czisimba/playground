#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace::std;
typedef pair<string, int> Author;

int main()
{ 
    pair<string, string> anon;
    pair<string, int> word_count;
    pair<string, vector<int> > line;
    Author author = make_pair("cz", 18);
    cout << "name:" << author.first << " age:"<< author.second << endl;

    return 0;
}
