#include "app.hpp"

#include <string>

App::App(/* args */)
    : _product(nullptr)
{
}

App::~App()
{
    if (_product)
    {
        delete _product;
    }
}

void App::doSomething()
{
    if (!_product)
    {
        _product = factoryMethod();
    }
    _product->doSomething();
}