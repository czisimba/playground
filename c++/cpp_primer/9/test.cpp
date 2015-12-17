#include <iostream>
#include <vector>

using namespace::std;

int main()
{
    vector<int> v;
    v.push_back(1);
    vector<int>::iterator first = v.begin(),
        last = v.end();
    int cnt = 100;
    // diaster: behavior of this loop is undefined
    while (first != last) {
        // do some processing
        // insert new value and reassign first, which otherwise would be invalid
        first = v.insert(first, 42);
        ++first;  // advance first just past the element we added
        /*
        if (cnt != 0)
        {
            cout << cnt <<endl;
            cnt--;
        }
        */
    }

    return 0;
}
