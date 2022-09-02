#if __linux__ or __APPLE__
#   ifdef DC_DYNAMIC_LIBRARY_BUILD
#       define EXPORT_SYSMBOL __attribute__((visibility("default")))
#       define INTERNAL_SYSMBOL __attribute__((visibility("hidden")))
#   else
#       define EXPORT_SYSMBOL
#       define INTERNAL_SYSMBOL
#   endif
#else
#   ifdef DC_DYNAMIC_LIBRARY_BUILD
#       define EXPORT_SYSMBOL __declspec(dllexport)
#   else
#       define EXPORT_SYSMBOL __declspec(dllimport)
#   endif
#   define INTERNAL_SYSMBOL
#endif


EXPORT_SYSMBOL int func();

class EXPORT_SYSMBOL MyClass
{
private:
    /* data */
public:
    MyClass(/* args */);
    ~MyClass();
};