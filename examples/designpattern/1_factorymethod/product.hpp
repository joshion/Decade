#pragma once

class Product
{
private:
    /* data */
public:
    Product(/* args */);
    virtual ~Product();

public:
    virtual void doSomething() = 0;

private:
    int _data;
};
