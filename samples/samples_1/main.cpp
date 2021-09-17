#include <iostream>

#include "dctemplate.hpp"

class TestSingleton : public Singleton<TestSingleton>
{
friend class Singleton<TestSingleton>;
protected:
    TestSingleton() { std::cout << "Create instance" << std::endl; };
public:
    ~TestSingleton() { std::cout << "Destroy instance" << std::endl; };

public:
    void dosomething() { std::cout << "Hello Decade." << std::endl; };
};

int main()
{
    TestSingleton::instance().dosomething();
    return 0;
}
