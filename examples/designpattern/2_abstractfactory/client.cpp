#include "client.hpp"

Client::Client(const Abstractfactory& factory)
    : _factory(factory)
{
}

Client::~Client()
{
}

void Client::doSomething()
{
    auto keyboard = _factory.createKeyBoard();
    auto mouse = _factory.createMouse();
}