//
//  main.cpp
//  TextQuery
//
//  Created by nichola on 15/12/1.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class TextQuery {
public:
    // typedef to make declarations easier
    typedef vector<string>::size_type line_no;
    /*
     * interface:
     * read_file builds internal data structures for the givenfile
     * run_query finds the given word and returns set of lines on which it appears
     * text_line returns a requested line from the input file
     */
    void read_file(ifstream &is) {
        store_file(is);
        build_map();
    }
    void show_query(const string &) const;
    set<line_no> run_query(const string &) const;
    string text_line(line_no) const;
private:
    // utility functions used by read_file
    void store_file(ifstream &);// store input file to vector
    void build_map(); // associated each word with a set of line numbers
    // remember the whole input file
    vector<string> lines_of_text;
    map< string, set<line_no> > word_map;
};

void TextQuery::store_file(ifstream &infile) {
    string line;
    while (getline(infile, line)) {
        lines_of_text.push_back(line);
    }
}
void TextQuery::build_map() {
    string word;
    for (int idx = 0; idx < lines_of_text.size(); ++idx) {
        istringstream line_s(lines_of_text[idx]);
        while (line_s >> word)
            word_map[word].insert(idx + 1);
    }
}
set<TextQuery::line_no> TextQuery::run_query(const string &s) const {
    map< string, set<line_no> >::const_iterator iter = word_map.find(s);
    return iter->second;
}
string TextQuery::text_line(line_no ln) const {
    return lines_of_text[ln - 1];
}
void TextQuery::show_query(const string &s) const {
    set<line_no> st = run_query(s);
    cout << s << " appear " << st.size() << " times" << endl;
    for (set<line_no>::const_iterator iter = st.begin(); iter != st.end(); ++iter) {
        cout << "line (" << *iter << ") :" << text_line(*iter) << endl;
    }
}

int main(int argc, const char * argv[]) {
    TextQuery TQ;
    ifstream infile;
    infile.open("/Users/nichola/百度云同步盘/cpp_primer/15/TextQuery/words_file");
    if (!infile) {
        cerr << "error,unable to open infile" << endl;
        return -1;
    }
    TQ.read_file(infile);
    TQ.show_query("cz");
    
    return 0;
}
