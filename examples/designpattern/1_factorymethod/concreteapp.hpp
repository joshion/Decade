#include "app.hpp"

class ConcreteApp : public App
{
private:
    /* data */
public:
    ConcreteApp(/* args */);
    ~ConcreteApp();

protected:
    // This is the kernel of the Design Pattern "Factory Method";
    Product* factoryMethod() override;
};

