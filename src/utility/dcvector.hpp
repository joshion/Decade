#pragma once

#include <type_traits>
#include <initializer_list>
#include <exception>

#include <cmath>

namespace DcMath
{
    //! A "column vector" template class.
    /*!
        VectorN = [a1, a2, a3, ..., an]T;
        In other style, as below.
        { a1, }
        { a2, }
        { ... }
        { an, }
     */
    template <class T, unsigned int length>
    class VectorN
    {
        static_assert(std::is_same_v<T, short> || std::is_same_v<T, int> || std::is_same_v<T, unsigned int> ||
                          std::is_same_v<T, long> || std::is_same_v<T, long long> || std::is_same_v<T, float> ||
                          std::is_same_v<T, double>,
                      "Unsupported elements' type.");

        static_assert(std::is_pod<T>::value,
                      "If you want to enhance this template, please ensure that the element's type be a pod type");
        static_assert(1 <= length && length <= 4, "The vector's length must in [1, 4]");

    public:
        using element_type = T;
        using vec_type = VectorN<T, length>;
        constexpr static const unsigned int kLength = length;
        constexpr static const unsigned int kByteSize = sizeof(T) * length;

    public:
        VectorN() = default;
        ~VectorN() = default;

        VectorN(std::initializer_list<T> vars)
        {
            if (vars.size() > length)
            {
                throw std::exception();
            }
            unsigned int i = 0;
            for (auto &a : vars)
            {
                _data[i++] = a;
            }
            for (; i < length; ++i)
            {
                _data[i] = T();
            }
        }

        template <auto len = length, unsigned int otherLen, std::enable_if_t<len >= otherLen> * = nullptr>
        VectorN(const VectorN<T, otherLen> &other)
        {
            assign(other);
        }

        VectorN(T var)
        {
            for (auto &i : _data)
            {
                i = var;
            }
        }

        auto &operator=(std::initializer_list<T> vars)
        {
            if (vars.size() > length)
            {
                throw std::exception();
            }
            unsigned int i = 0;
            for (auto &a : vars)
            {
                _data[i++] = a;
            }
            for (; i < length; ++i)
            {
                _data[i] = T();
            }
            return *this;
        }

        auto &operator=(const vec_type &other)
        {
            auto temp(other);
            assign(temp);
            return *this;
        }

        auto &operator=(T var)
        {
            for (auto &i : _data)
            {
                i = var;
            }
            return *this;
        }

        auto operator-(const vec_type &other) const
        {
            vec_type result;
            for (unsigned int i = 0; i < length; ++i)
            {
                result[i] = _data[i] - other._data[i];
            }
            return std::move(result);
        }

        auto &operator-=(const vec_type &other)
        {
            auto result = operator-(other);
            assign(result);
            return *this;
        }

        auto operator+(const vec_type &other) const
        {
            vec_type result;
            for (unsigned int i = 0; i < length; ++i)
            {
                result[i] = _data[i] + other._data[i];
            }
            return std::move(result);
        }

        auto &operator+=(const vec_type &other)
        {
            auto result = operator+(other);
            assign(result);
            return *this;
        }

        auto operator*(const vec_type &other) const
        {
            vec_type result;
            for (unsigned int i = 0; i < length; ++i)
            {
                result[i] = _data[i] * other._data[i];
            }
            return std::move(result);
        }

        auto &operator*=(const vec_type &other)
        {
            auto result = operator*(other);
            assign(result);
            return *this;
        }

        auto operator*(T var) const
        {
            vec_type result;
            for (unsigned int i = 0; i < length; ++i)
            {
                result[i] = _data[i] * var;
            }
            return std::move(result);
        }

        auto &operator*=(T var)
        {
            auto result = operator*(var);
            assign(result);
            return *this;
        }

        auto operator/(const vec_type &other) const
        {
            vec_type result;
            for (unsigned int i = 0; i < length; ++i)
            {
                result[i] = _data[i] / other._data[i];
            }
            return std::move(result);
        }

        auto &operator/=(const vec_type &other)
        {
            auto result = operator/(other);
            assign(result);
            return *this;
        }

        auto operator/(T var) const
        {
            if (std::is_same_v<T, double> || std::is_same_v<T, float>)
            {
                if (var == static_cast<T>(0.0))
                {
                    throw std::exception();
                }
            }

            vec_type result;
            for (unsigned int i = 0; i < length; ++i)
            {
                result[i] = _data[i] / var;
            }
            return std::move(result);
        }

        auto &operator/=(T var)
        {
            auto result = operator/(var);
            assign(result);
            return *this;
        }

        auto operator==(const vec_type &other) const
        {
            if (&other == this)
            {
                return true;
            }
            for (unsigned int i = 0; i < length; ++i)
            {
                if (_data[i] != other._data[i])
                {
                    return false;
                }
            }
            return true;
        }

        auto operator!=(const vec_type &other) const
        {
            return !operator==(other);
        }

        T &operator[](unsigned int n)
        {
            if (n < 0 || n >= length)
            {
                throw std::exception();
            }
            return _data[n];
        }

        const T &operator[](unsigned int n) const
        {
            if (n < 0 || n >= length)
            {
                throw std::exception();
            }
            return _data[n];
        }

        operator const T *() const
        {
            return _data;
        }

        operator T *()
        {
            return _data;
        }

        const T *data() const
        {
            return _data;
        }

        unsigned int size() const
        {
            return length;
        }

        auto begin()
        {
            T *p = &(_data[0]);
            return p;
        }

        auto end()
        {
            // Maybe here is a problem, because out of range in _data.
            T *p = &(_data[length]);
            return p;
        }

        auto begin() const
        {
            const T *p = &(_data[0]);
            return p;
        }

        auto end() const
        {
            // Maybe here is a problem, because out of range in _data.
            const T *p = &(_data[length]);
            return p;
        }

    public:
        /*! \brief Normalize the vector

                    A
            A' =  -----
                   |A|
        */
        auto normalize() const
        {
            auto len = T();
            for (auto &a : _data)
            {
                len += a * a;
            }
            len = static_cast<T>(sqrt(len));
            //
            if (len <= 0)
            {
                return vec_type();
            }
            auto result = vec_type();
            for (unsigned int i = 0; i < length; ++i)
            {
                result._data[i] = _data[i] / len;
            }
            return std::move(result);
        }

        /*! \brief Get the result of two vectors' dot multiplication

             result = A * B;
             result = a1 * b1 + a2 * b2 + ... * ... + an * bn;
        */
        auto dot(const vec_type &other) const
        {
            T result = T();
            for (unsigned int i = 0; i < length; ++i)
            {
                result += _data[i] * other._data[i];
            }
            return std::move(result);
        }

        /*! \brief Get the result of two vectors' cross multiplication

            C = A X B;
            { c1 }   { a1 }   { b1 }
            { c2 } = { a2 } X { b2 }
            { c3 }   { a3 }   { b3 }

            { c1 } = { a2 } \/ { b2 }
                     { a3 } /\ { b3 } = a2 * b3 - b2 * a3;
            { c2 } = ...;
            { c3 } = ...;
        */
        template <unsigned int len = length, std::enable_if_t<len == 3> * = nullptr>
        auto cross(const vec_type &other) const
        {
            auto result = vec_type();
            result._data[0] = _data[1] * other._data[2] - _data[2] * other._data[1];
            result._data[1] = _data[2] * other._data[0] - _data[0] * other._data[2];
            result._data[2] = _data[0] * other._data[1] - _data[1] * other._data[0];
            return std::move(result);
        }

    protected:
        template <auto len = length, unsigned int otherLen, std::enable_if_t<len >= otherLen> * = nullptr>
        void assign(const VectorN<T, otherLen> &other)
        {
            memcpy_s(_data, sizeof(T) * length, other, sizeof(T) * otherLen);
        }

    private:
        T _data[length] = {T()};
    };

    template <class Type, class T, unsigned int length, std::enable_if_t<std::is_same_v<Type, T>> * = nullptr>
    auto operator*(Type var, const VectorN<T, length> &other)
    {
        auto temp = other;
        return std::move(temp *= var);
    }
} // namespace DcMath
