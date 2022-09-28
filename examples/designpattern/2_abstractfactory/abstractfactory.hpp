#pragma once
#include "mouse.hpp"
#include "keyboard.hpp"

class Abstractfactory
{
public:
    Abstractfactory(/* args */);
    virtual ~Abstractfactory();
public:
    virtual Mouse* createMouse() const = 0;
    virtual Keyboard* createKeyBoard() const = 0;
};
