#pragma once

namespace DC
{

    class Application
    {
    public:
        Application();
        ~Application();
    public:
        int exec();
    protected:
        virtual int run() = 0;
    };

} // namespace DC
