#include "client.hpp"
#include "prototype.hpp"

Client::Client(/* args */)
{
}

Client::~Client()
{
}

void Client::doSomething()
{
    auto product = Prototype::clone("ProductA");
    product->show();
}
