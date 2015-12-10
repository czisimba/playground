#include <iostream>
#include <vector>
#include <string>

using namespace::std;

int main()
{
    string line1 = "We were her pride of 10 she named us:";
    string line2 = "Benjamin, Phoenix, the Prodigal";
    string line3 = "and perspicacious pacific Suzanne";
    string sentence = line1 + ' ' + line2 + ' ' + line3;
    vector<string::size_type> longest_start, shortest_start;
    string::size_type len, longest_len = 0, shortest_len = string::npos;
    string::size_type pos = 0, pos_ret;

    sentence += ' ';// add space to help find
    while ((pos_ret = sentence.find_first_of(' ', pos)) != string::npos)
    {
        if (pos != pos_ret)
        {
            len = pos_ret - pos;
            if (len > longest_len)
            {
                longest_start.clear(); 
                longest_start.push_back(pos);
                longest_len = len;
            }
            else if (len == longest_len)
            {
                longest_start.push_back(pos);
            }

            if (len < shortest_len)
            {
                shortest_start.clear();
                shortest_start.push_back(pos);
                shortest_len = len;
            }
            else if (len == shortest_len)
            {
                shortest_start.push_back(pos);
            }
            pos = pos_ret;
        }
        pos++;
    }
    sentence.erase(sentence.end() - 1);// clear last space
    cout << "longest len:" << longest_len << endl;
    for (vector<string::size_type>::iterator iter = longest_start.begin(); iter != longest_start.end(); ++iter)
    {
        string s(sentence, *iter, longest_len);
        cout << s << endl;
    }

    cout << "shortest len:" << shortest_len << endl;
    for (vector<string::size_type>::iterator iter = shortest_start.begin(); iter != shortest_start.end(); ++iter)
    {
        string s(sentence, *iter, shortest_len);
        cout << s << endl;
    }
 
    return 0;
}
