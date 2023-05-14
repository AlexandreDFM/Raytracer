/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

Vector3D::Vector3D() : e{0, 0, 0}
{
}

Vector3D::Vector3D(double x, double y, double z) : e{x, y, z}
{
}

double Vector3D::x() const
{
    return e[0];
}

double Vector3D::y() const
{
    return e[1];
}

double Vector3D::z() const
{
    return e[2];
}

Vector3D Vector3D::operator-() const
{
    return {-e[0], -e[1], -e[2]};
}

double Vector3D::operator[](int i) const
{
    return e[i];
}

double &Vector3D::operator[](int i)
{
    return e[i];
}

Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vector3D &Vector3D::operator*=(double t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vector3D &Vector3D::operator/=(double t)
{
    return *this *= 1 / t;
}

double Vector3D::length() const
{
    return std::sqrt(length_squared());
}

double Vector3D::length_squared() const
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

bool Vector3D::near_zero() const
{
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

Vector3D operator+(const Vector3D &u, const Vector3D &v)
{
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
}

Vector3D operator-(const Vector3D &u, const Vector3D &v)
{
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
}

Vector3D operator*(const Vector3D &u, const Vector3D &v)
{
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]};
}

Vector3D operator*(double t, const Vector3D &v)
{
    return {t * v.e[0], t * v.e[1], t * v.e[2]};
}

Vector3D operator*(const Vector3D &v, double t)
{
    return t * v;
}

Vector3D operator/(Vector3D v, double t)
{
    return (1 / t) * v;
}

Vector3D Vector3D::random()
{
    return {Math::random_double(), Math::random_double(), Math::random_double()};
}

Vector3D Vector3D::random(double min, double max)
{
    return { Math::random_double(min, max), Math::random_double(min, max), Math::random_double(min, max) };
}

double Vector3D::dot(const Vector3D &u, const Vector3D &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

Vector3D Vector3D::cross(const Vector3D &u, const Vector3D &v)
{
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]};
}

Vector3D Vector3D::unitVector(Vector3D v)
{
    return v / v.length();
}

Vector3D Vector3D::randomInUnitSphere()
{
    while (true) {
        auto p = Vector3D::random(-1, 1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

Vector3D Vector3D::randomUnitVector()
{
    return unitVector(randomInUnitSphere());
}

Vector3D Vector3D::reflect(const Vector3D &v, const Vector3D &n)
{
    return v - 2 * dot(v, n) * n;
}

Vector3D Vector3D::refract(const Vector3D &uv, const Vector3D &n, double etaiOverEtat)
{
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    Vector3D r_out_perp = etaiOverEtat * (uv + cos_theta * n);
    Vector3D r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}
