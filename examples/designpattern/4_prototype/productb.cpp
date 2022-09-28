#include "productb.hpp"

ProductB::ProductB(/* args */)
{
}

ProductB::~ProductB()
{
}

Prototype* ProductB::clone()
{
    return new ProductB(*this);
}

void ProductB::show()
{
    
}

PROTOTYPE_REGISTER(ProductB);