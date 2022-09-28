#pragma once
#include <map>
#include <string>

class Prototype
{
private:
    /* data */
public:
    Prototype(/* args */);
    ~Prototype();

public:
    virtual void show() = 0;
    virtual Prototype* clone() = 0;
    // virtual void initialize() = 0;

public:
    static Prototype* clone(const std::string& type);
    static std::map<std::string, Prototype*> sPrototypes;
};

#define DC_CONVERT_TO_STR1(var) #var

#define DC_CONVERT_TO_STR(var) DC_CONVERT_TO_STR1(var)

#define PROTOTYPE_REGISTER(type, ...) \
    class type##REGISTER \
    { \
    public: \
        type##REGISTER() \
        { \
            Prototype::sPrototypes[DC_CONVERT_TO_STR(type)] = static_cast<Prototype*> ( new type{__VA_ARGS__} ); \
        }; \
    }; \
    static type##REGISTER s_##type##REGISTER;
