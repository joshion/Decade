#include "singleton.hpp"

#include <iostream>
#include <future>

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

int main(int argc, char** argv)
{
    std::future<int> a = std::async([]{
        TestSingleton::instance().dosomething();
        return 1;
    });
    TestSingleton::instance().dosomething();
    int c = a.get() + 1;
    return 0;
}
