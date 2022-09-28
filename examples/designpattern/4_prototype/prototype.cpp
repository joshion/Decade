#include "prototype.hpp"

Prototype::Prototype(/* args */)
{
}

Prototype::~Prototype()
{
}

std::map<std::string, Prototype*> Prototype::sPrototypes;

Prototype* Prototype::clone(const std::string& type)
{
    if (sPrototypes.end() == sPrototypes.find(type))
    {
        return nullptr;
    }

    return sPrototypes[type]->clone();
}