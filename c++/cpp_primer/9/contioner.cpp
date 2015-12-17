#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace::std;

int main()
{
    int ia[7] = { 0, 1, 1, 2, 3, 5, 8 };
    string sa[6] = {
              "Fort Sumter", "Manassas", "Perryville",
               "Vicksburg", "Meridian",
               "Chancellorsville" };
    vector<string> svec(sa, sa + 6);
    list<int> ilist(ia + 4, ia + 6);
    vector<int> ivec(ia, ia + 100);
    list<string> slist(sa + 6, sa);
}
