#pragma once

#include <string>
#include <memory>

namespace DC
{

    class Command
    {
    public:
        explicit Command(const char *name);
        ~Command();

        virtual void run() = 0;

    private:
        std::string _name;
    };

    using CommandPtr = std::shared_ptr<Command>;

} // namespace DC

