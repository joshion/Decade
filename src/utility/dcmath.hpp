#pragma once

#include "dcmatrix.hpp"
#include "dcvector.hpp"

#include <cmath>

namespace DcMath
{
    const static double PI = 3.1415926535897;
    const static double RAD = 57.29577951308402;

    template <class T, unsigned int size>
    using MatrixN = MatrixNM<T, size, size>;

    template <class T>
    using Matrix3 = MatrixN<T, 3>;

    template <class T>
    using Matrix4 = MatrixN<T, 4>;

    template <class T>
    using Vector3 = VectorN<T, 3>;

    template <class T>
    using Vector4 = VectorN<T, 4>;

    using Matrix3i = Matrix3<int>;
    using Matrix3f = Matrix3<float>;
    using Matrix3d = Matrix3<double>;

    using Matrix4i = Matrix4<int>;
    using Matrix4f = Matrix4<float>;
    using Matrix4d = Matrix4<double>;

    using Vector3i = Vector3<int>;
    using Vector3f = Vector3<float>;
    using Vector3d = Vector3<double>;

    using Vector4i = Vector4<int>;
    using Vector4f = Vector4<float>;
    using Vector4d = Vector4<double>;

    template <class T>
    auto deg2rad(const T &deg)
    {
        return static_cast<T>(deg / RAD);
    }

    template <class T>
    auto rad2deg(const T &rad)
    {
        return static_cast<T>(rad * RAD);
    }

    template <class T, unsigned int size>
    auto identity()
    {
        auto result = MatrixN<T, size>();
        for (unsigned int i = 0; i < size; ++i)
        {
            result[i][i] = static_cast<T>(1);
        }
        return std::move(result);
    }

    template <class T, unsigned int size, std::enable_if_t<1 <= size && size <= 3> * = nullptr>
    auto translate(const VectorN<T, size> &vec)
    {
        auto result = identity<T, size + 1>();
        for (unsigned int i = 0; i < size; ++i)
        {
            result[size][i] = vec[i];
        }
        return std::move(result);
    }

    template <class T, unsigned int size, std::enable_if_t<1 <= size && size <= 4> * = nullptr>
    auto scale(const T &s)
    {
        auto result = identity<T, size>();
        constexpr static const unsigned int temp = size - 1;
        for (unsigned int i = 0; i < temp; ++i)
        {
            result[i][i] *= s;
        }
        return std::move(result);
    }

    template <class T, unsigned int size, std::enable_if_t<1 <= size && size <= 3> * = nullptr>
    auto scale(const VectorN<T, size> &vec)
    {
        auto result = identity<T, size + 1>();
        for (unsigned int i = 0; i < size; ++i)
        {
            result[i][i] = vec[i];
        }
        return std::move(result);
    }

#pragma region Some function only when the T is float or double

    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto rotate(const T &angle)
    {
        T cosA = static_cast<T>(cos(deg2rad(angle)));
        T sinA = static_cast<T>(sin(deg2rad(angle)));
        auto result = Matrix3<T>{{cosA, sinA, 0}, {-sinA, cosA, 0}, {0, 0, 1}};
        return std::move(result);
    }

    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto rotateX(const T &angle)
    {
        T cosA = static_cast<T>(cos(deg2rad(angle)));
        T sinA = static_cast<T>(sin(deg2rad(angle)));
        auto result = identity<T, 4>();
        result[1][1] = cosA;
        result[2][1] = -sinA;
        result[1][2] = sinA;
        result[2][2] = cosA;
        return std::move(result);
    }

    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto rotateY(const T &angle)
    {
        T cosA = static_cast<T>(cos(deg2rad(angle)));
        T sinA = static_cast<T>(sin(deg2rad(angle)));
        auto result = identity<T, 4>();
        result[0][0] = cosA;
        result[2][0] = -sinA;
        result[0][2] = sinA;
        result[2][2] = cosA;
        return std::move(result);
    }

    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto rotateZ(const T &angle)
    {
        T cosA = static_cast<T>(cos(deg2rad(angle)));
        T sinA = static_cast<T>(sin(deg2rad(angle)));
        auto result = identity<T, 4>();
        result[0][0] = cosA;
        result[1][0] = -sinA;
        result[0][1] = sinA;
        result[1][1] = cosA;
        return std::move(result);
    }

    // M == T * R;
    // V == M(-1) == R(-1) * T(-1);
    // V == R(T) * T(-1);
    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto lookAt(const Vector3<T> &eye, const Vector3<T> &at, const Vector3<T> &up)
    {
        auto forward = (at - eye).normalize();
        auto up1 = up.normalize();
        auto side = forward.cross(up1).normalize();
        auto up2 = side.cross(forward).normalize();

        auto result = Matrix4<T>{
            Vector3<T>{side[0], up2[0], -forward[0]},
            Vector3<T>{side[1], up2[1], -forward[1]},
            Vector3<T>{side[2], up2[2], -forward[2]},
            Vector4<T>{T(), T(), T(), static_cast<T>(1.0)},
        };
        result *= translate(Vector3<T>({-eye[0], -eye[1], -eye[2]}));
        return std::move(result);
    }

#pragma push_macro("near")
#pragma push_macro("far")
#undef near
#undef far
    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto ortho(T left, T right, T bottom, T top, T near, T far)
    {
        T width = right - left;
        T height = top - bottom;
        T length = near - far;
        auto result = identity<T, 4>();
        result[0][0] = static_cast<T>(2.0) / width;
        result[1][1] = static_cast<T>(2.0) / height;
        result[2][2] = static_cast<T>(2.0) / length;
        result[3][0] = -(right + left) / width;
        result[3][1] = -(top + bottom) / height;
        result[3][2] = -(far + near) / length;
        return std::move(result);
    }

    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto perspective(T left, T right, T bottom, T top, T near, T far)
    {
        T width = right - left;
        T height = top - bottom;
        T length = near - far;
        auto result = Matrix4<T>();
        result[0][0] = static_cast<T>(2.0) * near / width;
        result[1][1] = static_cast<T>(2.0) * near / height;
        result[2][2] = (near + far) / length;
        result[3][0] = -(right + left) / width;
        result[3][1] = -(top + bottom) / height;
        result[3][2] = -static_cast<T>(2.0) * near * far / length;
        result[2][3] = static_cast<T>(1.0);
        return std::move(result);
    }

    template <class T, std::enable_if_t<(std::is_same_v<T, float> || std::is_same_v<T, double>)> * = nullptr>
    auto perspective(T angle, T aspect, T near, T far)
    {
        T length = near - far;
        T yy = static_cast<T>(1.0 / tan(deg2rad(angle) / 2.0));
        auto result = Matrix4<T>();
        // aspect = width / height
        result[0][0] = yy / aspect;
        result[1][1] = yy;
        result[2][2] = (near + far) / length;
        result[3][2] = -static_cast<T>(2.0) * near * far / length;
        result[2][3] = static_cast<T>(1.0);
        return std::move(result);
    }
#pragma pop_macro("far")
#pragma pop_macro("near")

#pragma endregion
} // namespace DcMath
