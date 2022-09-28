#include "client.hpp"
#include "logifactory.hpp"

int main(int argc, char** argv)
{
    LogiFactory factory;
    Client client(factory);
    client.doSomething();
    return 0;
}
