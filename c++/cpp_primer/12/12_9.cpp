#include <iostream>
#include <string>

using namespace::std;

class Screen {
public:
    Screen(string c = ""):contents(c) {
    }
    Screen(int higt, int wid, string c):height(higt),width(wid),contents(c) {
    }
private:
    string contents;
    int cursor;
    int height, width;
};

int main()
{
    Screen hp(18, 15, "starting...");

    return 0;
}
