#include "abstractfactory.hpp"

class LogiFactory : public Abstractfactory
{
private:
    /* data */
public:
    LogiFactory(/* args */);
    ~LogiFactory();
public:
    Mouse* createMouse() const override;
    Keyboard* createKeyBoard() const override;
};
