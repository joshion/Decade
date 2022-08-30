#pragma once

#include "application.hpp"
#include "command.hpp"

namespace DC
{

    class CoreApplication : public DC::Application
    {
    private:
        /* data */
    public:
        CoreApplication(/* args */);
        ~CoreApplication();

    protected:
        int run() override;
    };

    bool postCommnad(const CommandPtr& pCommand);
    bool sendCommand(const CommandPtr& pCommand);

} // namespace DC
