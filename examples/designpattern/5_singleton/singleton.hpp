#pragma once

#include <memory>
#include <mutex>

template <class T>
class Singleton
{
protected:
    Singleton() = default;
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;

public:
    virtual ~Singleton() = default;

public:
    template <class... Types>
    static T& instance(Types... args)
    {
        static std::once_flag flag;
        std::call_once(flag, [&]() { _instance = std::shared_ptr<T>(new T(args...)); });
        return *_instance;
    }

private:
    static std::shared_ptr<T> _instance;
};

template <class T>
std::shared_ptr<T> Singleton<T>::_instance;