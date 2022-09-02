#include "generalcommand.hpp"
#include "coreapplication.hpp"

int main(int argc, char** argv)
{
    DC::CoreApplication app;
    DC::CommandPtr cmd = std::make_shared<DC::GeneralCommand>("First Command");
    DC::postCommnad(cmd);

    DC::CommandPtr cmd2 = std::make_shared<DC::GeneralCommand>("Second Command");
    DC::sendCommand(cmd2);

    app.exec();
    return 0;
}
