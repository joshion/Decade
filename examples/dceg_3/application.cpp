#include "application.hpp"

using namespace DC;

DC::Application *dcApp = nullptr;

Application::Application()
    : _mainThreadID(std::this_thread::get_id())
{
    dcApp = this;
}

Application::~Application()
{
}

std::thread::id Application::mainThreadID()
{
    return _mainThreadID;
}

int Application::exec()
{
    return run();
}