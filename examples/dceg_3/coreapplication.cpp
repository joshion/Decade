#include "coreapplication.hpp"

#include "dctemplate.hpp"

#include <list>
#include <chrono>
#include <thread>

using namespace DC;

class CommandManager : public Singleton<CommandManager>
{
friend class Singleton<CommandManager>;
protected:
    CommandManager() {}
public:
    ~CommandManager() {}
public:
    void addCommand(const CommandPtr& pCommand);
    void execCommnad();

public:
    std::list<CommandPtr> _commands;
};

void CommandManager::addCommand(const CommandPtr& pCommand)
{
    _commands.push_back(pCommand);
}

void CommandManager::execCommnad()
{
    if (_commands.empty())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return;
    }
    auto command = _commands.front();
    _commands.pop_front();
    command->run();
}


CoreApplication::CoreApplication()
    : Application()
{
}

CoreApplication::~CoreApplication()
{
}

int CoreApplication::run()
{
    do
    {
        CommandManager::instance().execCommnad();
    } while (true);
    return 0;
}

bool DC::postCommnad(const CommandPtr& pCommand)
{
    CommandManager::instance().addCommand(pCommand);
    return true;
}

bool DC::sendCommand(const CommandPtr& pCommand)
{
    return true;
}