#include "producta.hpp"

ProductA::ProductA(/* args */)
{
}

ProductA::~ProductA()
{
}

Prototype* ProductA::clone()
{
    return new ProductA(*this);
}

void ProductA::show()
{
    
}

PROTOTYPE_REGISTER(ProductA);
