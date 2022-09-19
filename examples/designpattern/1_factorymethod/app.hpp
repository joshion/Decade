#pragma once
#include "product.hpp"

class App
{
private:
    /* data */
public:
    App(/* args */);
    virtual ~App();

public:
    void doSomething();

protected:
    // This is the kernel of the Design Pattern "Factory Method";
    virtual Product* factoryMethod() = 0;
private:
    Product* _product;
};

