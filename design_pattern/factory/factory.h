class ProductBase {
public:
    ProductBase() {};
    ~ProductBase() {};
};

class BookProduct:public ProductBase {
public:
    BookProduct() {};
    ~BookProduct() {};
};

class FactoryBase {
public:
    FactoryBase() {};
    ~FactoryBase() {};
    virtual ProductBase * CreateProduct() = 0;
};

class BookFactory:public FactoryBase {
public:
    BookFactory() {};
    ~BookFactory() {};

    virtual ProductBase * CreateProduct() {
        //return (ProductBase *)(new BookProduct());
        return new BookProduct();
    };
};
