#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace::std;

int main()
{
    ifstream bookshelf("./bookshelf"), readed_list("readed_list");
    vector<string> books;
    vector<string>::size_type read_idx;
    set<string> reading,readed;
    string book;

    // init
    while (bookshelf >> book)
    {
        books.push_back(book);
    }
    while (readed_list >> book)
    {
        readed.insert(book);
    }
    srand(time(0));

    // begin of the month 
    for (int mon = 0; mon != 10; ++mon)
    {
        cout << "################### month " << mon << " ###################"<< endl;
        // get books reading finish
        for (set<string>::iterator iter = reading.begin(); iter != reading.end(); ++iter)
        {
            if (rand() % 2 == 0)// 50% reading finish
            {
                cout << "book:[" << *iter << "] reading finish" << endl;
                readed.insert(*iter);
                reading.erase(iter);
                break;
            }
        }

        // put new book to reading list
        read_idx = rand() % books.size();
        if (!reading.count(books[read_idx]) && !readed.count(books[read_idx]) && 
                reading.size() != 3)// most reading 3 books same time
        {
            cout << "add new book:[" <<  books[read_idx] << "] to reading list" << endl;
            reading.insert(books[read_idx]);
        }

        // print reading && readed list every month
        cout << "reading list:" << endl;
        for (set<string>::iterator iter = reading.begin(); iter != reading.end(); ++iter)
        {
            cout << *iter << " | ";
        }
        cout << endl;
        cout << "readed list:" << endl;
        for (set<string>::iterator iter = readed.begin(); iter != readed.end(); ++iter)
        {
            cout << *iter << " | ";
        }
        cout << endl;
        cout << endl;
        sleep(1);
    }

    return 0;
}
