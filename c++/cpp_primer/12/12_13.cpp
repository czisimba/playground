#include <iostream>
#include <string>
#include <unistd.h>

using namespace::std;

class Screen {
    typedef string::size_type index;
    string content;
    index height,width;
    index cursor;
    void do_display(ostream &ost) const {//use for reload functions
        index idx = 0;
        while (idx < content.size())
        {
            ost << content[idx++];
            if (idx % width == 0)
                ost << endl;
        }
    }
public:
    Screen(index higt, index wid, const string &cont);
    Screen &move(index higt, index wid);
    Screen &set(string cont);
    Screen &set(char cont);
    const Screen &display (ostream &ost) const;// for const object
    Screen &display (ostream &ost);
};

Screen::Screen(index higt, index wid, const string &cont = ""):height(higt),width(wid),cursor(0),content(cont) {
    content.assign(higt * wid, ' ');// alloc all window space
    if (cont.size() != 0)
        content.replace(0, cont.size(), cont);
}
Screen& Screen::move(index r, index c) {
    if (r > height || c > width) {// check invalid row, column
        cerr << "invalid row or column" << endl;
        throw 0;
    }

    cursor = r * width + c;//start from line 1
    return *this;
}
Screen& Screen::set(char cont) {
    content[cursor] = cont;
    return *this;
}

Screen& Screen::display(ostream &ost) {
    do_display(ost);
    return *this;
}

const Screen& Screen::display(ostream &ost) const {
    do_display(ost);
    return *this;
}

int main()
{
    Screen hp(20, 80, "");

    hp.move(0,0).set('#').display(cout);
    usleep(500000);
    hp.move(0,1).set('H').display(cout);
    usleep(500000);
    hp.move(0,2).set('e').display(cout);
    usleep(500000);
    hp.move(0,3).set('l').display(cout);
    usleep(500000);
    hp.move(0,4).set('l').display(cout);
    usleep(500000);
    hp.move(0,5).set('o').display(cout);
    usleep(500000);
    hp.move(0,6).set('!').display(cout);
    sleep(2);

    return 0;
}
