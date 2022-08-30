#include "command.hpp"

namespace DC
{
    class GeneralCommand : public Command
    {
    public:
        explicit GeneralCommand(const char* name);
        ~GeneralCommand();

        void run() override;
    };

    using GeneralCommandPtr = std::shared_ptr<GeneralCommand>;
} // namespace DC
