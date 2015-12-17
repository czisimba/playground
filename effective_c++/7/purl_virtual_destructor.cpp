
class AWOV {
public:
    virtual ~AWOV() = 0;// pure virtual declaretion
};
AWOV::~AWOV() {}; // pure virtual defination

class Derive_Class:AWOV {
};

int main()
{
    Derive_Class dc;

    return 0;
}
