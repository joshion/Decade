#pragma once
#include "abstractfactory.hpp"

class Client
{
public:
    Client(const Abstractfactory& factory);
    ~Client();
public:
    void doSomething();
private:
    const Abstractfactory& _factory;
};

