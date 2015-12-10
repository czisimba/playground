#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace::std;

int main()
{
    ifstream words_src_file("./words"), exclude_src_file("./exclude");
    string word_src, exclude_src;
    set<string> exclude_words;
    vector<string> words;

    while (exclude_src_file >> exclude_src)
    {
        exclude_words.insert(exclude_src);
    }

    while (words_src_file >> word_src)
    {
        if (word_src[word_src.size() - 1] == 's' && exclude_words.count(word_src) == 0)
        {
            word_src.resize(word_src.size() - 1);
        }
        words.push_back(word_src);
    }

    for (vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter)
    {
        cout << *iter << ' ';
    }
    cout << endl;

    return 0;
}
