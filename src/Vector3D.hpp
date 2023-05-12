/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Vector3D
*/

#ifndef Vector3D_H
    #define Vector3D_H

    #include <cmath>
    #include <iostream>
    #include "Math/Math.hpp"

class Vector3D {
    public:
        Vector3D();
        Vector3D(double x, double y, double z);

        double x() const;
        double y() const;
        double z() const ;

        Vector3D operator-() const;
        double operator[](int i) const;
        double &operator[](int i);
        Vector3D &operator+=(const Vector3D &v);
        Vector3D &operator*=(const double t);
        Vector3D &operator/=(const double t);

        double length() const;
        double length_squared() const;

        static Vector3D random()
        {
            return Vector3D(Math::random_double(), Math::random_double(), Math::random_double());
        };

        static Vector3D random(double min, double max)
        {
            return Vector3D(Math::random_double(min, max), Math::random_double(min, max), Math::random_double(min, max));
        };

        bool near_zero() const;

    public:
        double e[3];
};

// Type aliases for Vector3D
using point3 = Vector3D;   // 3D point
using color = Vector3D;    // RGB color

// Vector3D Utility Functions

inline std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vector3D operator+(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vector3D operator-(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vector3D operator*(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vector3D operator*(double t, const Vector3D &v)
{
    return Vector3D(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vector3D operator*(const Vector3D &v, double t)
{
    return t * v;
}

inline Vector3D operator/(Vector3D v, double t)
{
    return (1 / t) * v;
}

inline double dot(const Vector3D &u, const Vector3D &v)
{
    return u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

inline Vector3D cross(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vector3D unit_vector(Vector3D v)
{
    return v / v.length();
}

inline Vector3D random_in_unit_sphere()
{
    while (true) {
        auto p = Vector3D::random(-1, 1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

inline Vector3D random_unit_vector()
{
    return unit_vector(random_in_unit_sphere());
}

inline Vector3D reflect(const Vector3D &v, const Vector3D &n)
{
    return v - 2 * dot(v, n) * n;
}

inline Vector3D refract(const Vector3D& uv, const Vector3D& n, double etai_over_etat)
{
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    Vector3D r_out_perp =  etai_over_etat * (uv + cos_theta * n);
    Vector3D r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

#endif
