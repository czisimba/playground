#include <iostream>
#include <vector>

using namespace::std;

class Exmpl {
public:
    Exmpl(){
        cout << "Exmpl()" << endl;
    }
    Exmpl(const Exmpl &ex) {
        cout << "Exmpl(Exmpl &ex)" << endl;
    }
    Exmpl &operator=(const Exmpl &ex) {
        cout << "operator=()" << endl;
        return *this;
    }
    ~Exmpl() {
        cout << "~Exmpl()" << endl;
    }
private:
    int ival;
};

void func1(Exmpl obj)
{
}

void func2(Exmpl &obj)
{
}

Exmpl func3()
{
    Exmpl obj;
    return obj;
}

int main()
{
    Exmpl exm1;
    Exmpl exm2(exm1);
    Exmpl exm3 = exm1;
    Exmpl *exm4 = new Exmpl;
    func1(exm1);
    func2(exm1);
    Exmpl exm5 = func3();
    vector<Exmpl> Ex_v(3);

    return 0;
}
