#include <iostream>
#include <ctime>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    clock_t start,finish;
    //C-style character string implementation
    const char *pc = "a very long literal string"; 
    const size_t len = strlen(pc +1); // space to allocate
    start = clock();
    // performance test on string allocation and copy
    for (size_t ix = 0; ix != 1000000; ++ix) {
        char *pc2 = new char[len + 1]; // allocate the allocated
        strcpy(pc2, pc);
        if (strcmp(pc2, pc))
                ;   // do nothing
        delete [] pc2;
    }
    finish = clock();
    cout << "c string cost:" << 1000 * (finish - start) / CLOCKS_PER_SEC << " ms" << endl;

    // string implementation
    string str("a very long literal string");
    start = clock();
    // performance test on string allocation and copy
    for (int ix = 0; ix != 1000000; ++ix) {
         string str2 = str; // do the copy, automatically
         if (str != str2)
             ; // do nothing
    }
    finish = clock();
    cout << "c++ string cost:" << 1000 * (finish - start) / CLOCKS_PER_SEC << " ms" << endl;
}
