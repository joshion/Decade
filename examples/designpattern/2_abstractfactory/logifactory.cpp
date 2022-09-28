#include "logifactory.hpp"
#include "logimouse.hpp"
#include "logikeyboard.hpp"


LogiFactory::LogiFactory(/* args */)
{
}

LogiFactory::~LogiFactory()
{
}

Mouse* LogiFactory::createMouse() const
{
    return static_cast<Mouse*>(new LogiMouse());
}

Keyboard* LogiFactory::createKeyBoard() const
{
    return static_cast<Keyboard*>(new LogiKeyboard());
}