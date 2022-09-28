#pragma once

#include "prototype.hpp"

class ProductB : public Prototype
{
private:
    /* data */
public:
    ProductB(/* args */);
    ~ProductB();

public:
    void show() override;
    Prototype* clone() override;
};
