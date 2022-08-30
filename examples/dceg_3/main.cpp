#include "generalcommand.hpp"
#include "coreapplication.hpp"

int main(int argc, char** argv)
{
    DC::CoreApplication app;
    DC::CommandPtr cmd = std::make_shared<DC::GeneralCommand>("First Command");
    DC::postCommnad(cmd);
    app.exec();
    return 0;
}
