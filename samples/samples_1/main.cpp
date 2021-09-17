#include <iostream>

#include "dctemplate.hpp"

#include "dcmath.hpp"

/*!
 * @brief Test Singleton's Compilation
*/
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

/*!
 * @brief Test DcMath's Compilation
*/
void TestDcMathCompile()
{
    DcMath::Matrix4d mat;
    mat = mat * mat;
}

int main()
{
    TestDcMathCompile();
    TestSingleton::instance().dosomething();
    return 0;
}
