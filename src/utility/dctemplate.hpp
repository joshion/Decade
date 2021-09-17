#pragma once

#include <memory>
#include <mutex>

template <typename SELF>
class Impl
{
public:
    inline virtual ~Impl()
    {
    }
    SELF* _self;
};

template <typename SELF, typename IMPL>
class pImpl
{
public:
    inline pImpl() : _impl(new IMPL)
    {
    }
    inline ~pImpl(void)
    {
        delete _impl;
    }
    inline IMPL* operator()(SELF* self)
    {
        _impl->_self = self;
        return _impl;
    }
    inline IMPL* get(void)
    {
        return _impl;
    }
    inline const IMPL* get(void) const
    {
        return _impl;
    }

protected:
    IMPL* _impl;

private:
    pImpl(const pImpl&) = delete;
    pImpl& operator=(const pImpl&) = delete;
    bool operator==(const pImpl& t) = delete;
    bool operator!=(const pImpl& t) = delete;
};

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

#define DC_DISABLE_COPY(C) \
    C(const C&) = delete;  \
    C& operator=(const C&) = delete
#define DC_DECLARE_IMPL(C) \
    friend class C##Impl;  \
    pImpl<C, C##Impl> _pImpl

#define DC_I(C) C##Impl* d = static_cast<C##Impl*>(_pImpl(this));
#define DC_E(C) C##Impl* d = static_cast<C##Impl*>(_pImpl.get());
#define DC_D(C) C##Impl* d = static_cast<C##Impl*>(_pImpl.get());
#define DC_C(C) const C##Impl* d = static_cast<const C##Impl*>(_pImpl.get());
#define DC_Q(C) C* q = _self;

#define DC_STATIC_DECLARE(C) friend class Singleton<C>
#define DC_STATIC_CREATE(C, ...) C##Impl::instance(__VA_ARGS__)
#define DC_SD(C, ...) C##Impl* sd = static_cast<C##Impl*>(C##Impl::instance(__VA_ARGS__)._pImpl.get());
#define DC_SQ(C, ...) C& sq = C##Impl::instance(__VA_ARGS__);
