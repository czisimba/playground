
class NoDefault {
    int ival;
public:
    NoDefault(int iv):ival(iv) {
    }
};
class C {
    NoDefault nd;
public:
    C():nd(0) {
    }
};

int main()
{
    C c;

    return 0;
}
