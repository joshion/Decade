#pragma once

#include "dcvector.hpp"

#include <type_traits>
#include <initializer_list>
#include <exception>

#include <cstring>

namespace DcMath
{
    //! A "column major mat" template class.
    /*!
                { a1,   b1,  c1, ... }\
                { a2,   b2,  c2, ... } \
                { a3,   b3,  c3, ... }  |==height
     MatrixNM = { ..., ..., ..., ... } /
                { an,   bn,  cn, ... }/
                 \                  /
                  \                /
                   \_____width____/
    */
    template <class T, unsigned int height, unsigned int width>
    class MatrixNM
    {
        static_assert(std::is_same_v<T, short> || std::is_same_v<T, int> || std::is_same_v<T, unsigned int> ||
                          std::is_same_v<T, long> || std::is_same_v<T, long long> || std::is_same_v<T, float> ||
                          std::is_same_v<T, double>,
                      "Unsupported elements' type.");

        static_assert(std::is_pod<T>::value,
                      "If you want to enhance this template, please ensure that the element's type be a pod type");
        static_assert(1 <= height && height <= 4, "The vector's length must in [1, 4]");
        static_assert(1 <= width && width <= 4, "The vector's length must in [1, 4]");

    public:
        using ElementType = T;
        using VectorType = VectorN<T, height>;
        using MatrixType = MatrixNM<T, height, width>;
        constexpr static unsigned int kVectorLength = VectorType::kLength;
        constexpr static unsigned int kVectorByteSize = VectorType::kByteSize;
        constexpr static unsigned int kDataLength = width * height;
        constexpr static unsigned int kDataByteSize = sizeof(T) * kDataLength;

    public:
        MatrixNM() = default;
        ~MatrixNM() = default;

        //!
        /*!
            {vars[1], vars[2], ... }
        */
        MatrixNM(const std::initializer_list<VectorType> &vars)
        {
            if (vars.size() > width)
            {
                throw std::exception();
            }
            unsigned int i = 0;
            for (auto &a : vars)
            {
                memcpy_s(_data[i++], kVectorByteSize, a, kVectorByteSize);
            }
        }

        //!
        /*!
            { vars[1], vars[n+1], ... }
            { vars[2], vars[n+2], ... }
            { ...    ,    ...   , ... }
            { vars[n], vars[n+n], ... }
        */
        MatrixNM(const std::initializer_list<T> &vars)
        {
            if (vars.size() > kDataLength)
            {
                throw std::exception();
            }
            unsigned int i = 0;
            T *p = _data[0];
            for (auto &a : vars)
            {
                *(p + i++) = a;
            }
        }

        MatrixNM(const MatrixType &other)
        {
            assign(other);
        }

        //!
        /*!
            { var, var, ... }
            { var, var, ... }
            { ..., ..., ... }
            { var, var, ... }
        */
        MatrixNM(const T &var)
        {
            T *p = _data[0];
            for (unsigned int i = 0; i < kDataLength; ++i)
            {
                *(p + i) = var;
            }
        }

        //!
        /*!
            {vars[1], vars[2], ... }
        */
        auto &operator=(const std::initializer_list<VectorType> &vars)
        {
            auto temp = MatrixType(vars);
            assign(temp);
            return *this;
        }

        //!
        /*!
            { vars[1], vars[n+1], ... }
            { vars[2], vars[n+2], ... }
            { ...    ,    ...   , ... }
            { vars[n], vars[n+n], ... }
        */
        auto &operator=(const std::initializer_list<T> &vars)
        {
            auto temp = MatrixType(vars);
            assign(temp);
            return *this;
        }

        auto &operator=(const MatrixType &other)
        {
            auto temp(other);
            assign(temp);
            return *this;
        }

        //!
        /*!
            { var, var, ... }
            { var, var, ... }
            { ..., ..., ... }
            { var, var, ... }
        */
        auto &operator=(const T &var)
        {
            auto temp = MatrixType(var);
            assign(temp);
            return *this;
        }

        //!
        /*!
            { c01, c11, ... }   { a01 - b01, a11 - b11, ... }
            { c02, c12, ... }   { a01 - b01, a12 - b12, ... }
            { ..., ..., ... } = {    ...   ,    ...   , ... }
            { c0n, c1n, ... }   { a0n - b0n, a1n - b12, ... }
        */
        auto operator-(const MatrixType &other) const
        {
            auto result = MatrixType();
            for (unsigned int i = 0; i < width; ++i)
            {
                result[i] = _data[i] - other._data[i];
            }
            return std::move(result);
        }

        auto &operator-=(const MatrixType &other)
        {
            auto temp = operator-(other);
            assign(temp);
            return *this;
        }

        //!
        /*!
            { c01, c11, ... }   { a01 + b01, a11 + b11, ... }
            { c02, c12, ... }   { a01 + b01, a12 + b12, ... }
            { ..., ..., ... } = {    ...   ,    ...   , ... }
            { c0n, c1n, ... }   { a0n + b0n, a1n + b12, ... }
        */
        auto operator+(const MatrixType &other) const
        {
            auto result = MatrixType();
            for (unsigned int i = 0; i < width; ++i)
            {
                result[i] = _data[i] + other._data[i];
            }
            return std::move(result);
        }

        auto &operator+=(const MatrixType &other)
        {
            auto temp = operator+(other);
            assign(temp);
            return *this;
        }

        template <unsigned int otherHeight = width, unsigned int otherWidth, std::enable_if_t<otherHeight == width> * = nullptr>
        auto operator*(const MatrixNM<T, otherHeight, otherWidth> &other) const
        {
            constexpr static const unsigned int resultWidth = otherWidth;
            constexpr static const unsigned int resultHeight = height;
            auto result = MatrixNM<T, resultHeight, resultWidth>();
            auto temp = this->transpose();

            for (unsigned int j = 0; j < resultWidth; ++j)
            {
                for (unsigned int i = 0; i < resultHeight; ++i)
                {
                    result[j][i] = temp[i].dot(other[j]);
                }
            }
            return std::move(result);
        }

        template <unsigned int h = height, unsigned int w = width, std::enable_if_t<w == h> * = nullptr>
        auto &operator*=(const MatrixType &other)
        {
            auto temp = operator*(other);
            assign(temp);
            return *this;
        }

        auto operator*(const T &var) const
        {
            auto result = MatrixType();
            for (unsigned int i = 0; i < width; ++i)
            {
                result[i] = _data[i] * var;
            }
            return std::move(result);
        }

        auto &operator*=(T var)
        {
            auto temp = operator*(var);
            assign(temp);
            return *this;
        }

        auto operator*(const VectorType &vec) const
        {
            auto temp = this->transpose();
            auto result = VectorType();
            for (unsigned int i = 0; i < width; ++i)
            {
                result[i] = temp[i].dot(vec);
            }
            return std::move(result);
        }

        auto operator/(const MatrixType &other) const
        {
            auto result = MatrixType();
            for (unsigned int i = 0; i < width; ++i)
            {
                result[i] = _data[i] / other._data[i];
            }
            return std::move(result);
        }

        auto &operator/=(const MatrixType &other)
        {
            auto temp = operator/(other);
            assign(temp);
            return *this;
        }

        auto operator/(T var) const
        {
            auto result = MatrixType();
            for (unsigned int i = 0; i < width; ++i)
            {
                result[i] = _data[i] / var;
            }
            return std::move(result);
        }

        auto &operator/=(T var)
        {
            auto temp = operator/(var);
            assign(temp);
            return *this;
        }

        auto &operator[](unsigned int n)
        {
            // Although the user write the code like this "MatrixNM a; a[-1];",
            // there would be an exception throw too, because -1 "is" 4294967295.
            if (n >= width)
            {
                throw std::exception();
            }
            return _data[n];
        }

        const auto &operator[](unsigned int n) const
        {
            if (n >= width)
            {
                throw std::exception();
            }
            return _data[n];
        }

        operator const T *() const
        {
            // const T* p = &(_data[0][0]);
            const T *p = _data[0];
            return p;
        }

        operator T *()
        {
            // T* p = &(_data[0][0]);
            T *p = _data[0];
            return p;
        }

        const T *data() const
        {
            // const T* p = &(_data[0][0]);
            const T *p = _data[0];
            return p;
        }

        unsigned int size() const
        {
            return kDataByteSize;
        }

        unsigned int w() const
        {
            return width;
        }

        unsigned int h() const
        {
            return height;
        }

    public:
        template <unsigned int resultW = height, unsigned int resultH = width>
        auto transpose() const
        {
            auto result = MatrixNM<T, resultH, resultW>();
            for (unsigned int i = 0; i < resultW; ++i)
            {
                for (unsigned int j = 0; j < resultH; ++j)
                {
                    result[i][j] = _data[j][i];
                }
            }
            return std::move(result);
        }

    protected:
        void assign(const MatrixType &other) noexcept
        {
            memcpy(_data, other._data, kDataByteSize);
        }

    private:
        VectorType _data[width]; /*!< the inner data. */
    };

    template <class Type, class T, unsigned int height, unsigned int width, std::enable_if_t<std::is_same_v<Type, T>> * = nullptr>
    auto operator*(Type var, const MatrixNM<T, height, width> &other)
    {
        auto temp = other;
        return std::move(temp *= var);
    }
} // namespace DcMath
