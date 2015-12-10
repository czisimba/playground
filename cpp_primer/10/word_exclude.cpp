#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace::std;

int get_word_count(ifstream &in_file, map<string, int> &word_count)
{
    string in_word;
    set<string> exclude_word;

    while (in_file >> in_word)
        exclude_word.insert(in_word);

    while (cin >> in_word)
    {
        if (exclude_word.count(in_word) == 0)
            word_count[in_word]++;
    }

    return 0;
}

int main()
{
    ifstream in_file("exclude_words");
    map<string, int> word_count;

    get_word_count(in_file, word_count);

    for (map<string, int>::iterator iter = word_count.begin(); iter != word_count.end(); ++iter)
    {
        cout << iter->first << ": " << iter->second << endl;
    }
    return 0;
}
