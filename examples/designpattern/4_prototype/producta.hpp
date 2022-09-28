#pragma once

#include "prototype.hpp"

class ProductA : public Prototype
{
private:
    /* data */
public:
    ProductA(/* args */);
    ~ProductA();

public:
    void show() override;
    Prototype* clone() override;
};

