#include <iostream>
#include <string>

class C {
public:
    C(const std::string &s):content(s) {
    }
    const char& operator[] (int num) const {
        return content[num];
    }
    char& operator[] (int num) {
        return const_cast<char &>(
                static_cast<const C&>(*this)[num]);
    }
private:
    std::string content;
};

int main()
{
    const C c("chengzhi");
    C c1("chengzhi");
    std::cout << c[5] << std::endl;
    std::cout << c1[5] << std::endl;
    //c[5] = 'a';
    //char *pc = &c[5];
    c1[5] = 'a';
    return 0;
}
