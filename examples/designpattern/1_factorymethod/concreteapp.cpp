#include "concreteapp.hpp"
#include "producta.hpp"

ConcreteApp::ConcreteApp(/* args */)
{
}

ConcreteApp::~ConcreteApp()
{
}

Product* ConcreteApp::factoryMethod()
{
    return new ProductA();
}