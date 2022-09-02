#pragma once

#include <thread>

namespace DC
{

    class Application
    {
    public:
        Application();
        ~Application();
    public:
        int exec();
        std::thread::id mainThreadID();
        virtual int run() = 0;
    private:
        std::thread::id _mainThreadID;
    };

} // namespace DC

extern DC::Application *dcApp;
