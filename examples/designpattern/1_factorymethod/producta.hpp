#include "product.hpp"

class ProductA : public Product
{
private:
    /* data */
public:
    ProductA(/* args */);
    ~ProductA();
public:
    void doSomething() override;
private:
    int _name;
};

