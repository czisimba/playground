
class X {
    int base,rem;
public:
    X (int i, int j):base(i),rem(base % j) {
    }
    X ():base(0),rem(0) {
    }
};

int main()
{
    X x;
    return 0;
}
