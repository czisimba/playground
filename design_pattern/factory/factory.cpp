#include "factory.h"

int main()
{
    BookFactory fac;
    ProductBase *pro = fac.CreateProduct();

    return 0;
}
