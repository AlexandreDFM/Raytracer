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
    return std::sqrt(lengthSquared());
}

double Vector3D::lengthSquared() const
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

bool Vector3D::nearZero() const
{
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
    Vector3D result;
    for (int i = 0; i < 3; i++) {
        result.e[i] = e[i] + other.e[i];
    }
    return result;
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
    Vector3D result;
    for (int i = 0; i < 3; i++) {
        result.e[i] = e[i] - other.e[i];
    }
    return result;
}

Vector3D Vector3D::operator*(const Vector3D& other) const
{
    Vector3D result;
    for (int i = 0; i < 3; i++) {
        result.e[i] = e[i] * other.e[i];
    }
    return result;
}

Vector3D Vector3D::operator*(double t) const
{
    return {t * e[0], t * e[1], t * e[2]};
}

Vector3D Vector3D::operator/(double t) const
{
    return *this * (1 / t);
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

Vector3D Vector3D::unitVector(Vector3D &v)
{
    return v / v.length();
}

Vector3D Vector3D::randomInUnitSphere()
{
    while (true) {
        auto p = Vector3D::random(-1, 1);
        if (p.lengthSquared() >= 1) continue;
        return p;
    }
}

Vector3D Vector3D::randomUnitVector()
{
    Vector3D v = randomInUnitSphere();
    return unitVector(v);
}

Vector3D Vector3D::reflect(const Vector3D &v, const Vector3D &n)
{
    return v - n * (2 * dot(v, n));
}

Vector3D Vector3D::refract(const Vector3D &uv, const Vector3D &n, double etaiOverEtat)
{
    auto cosTheta = fmin(dot(-uv, n), 1.0);
    Vector3D r_out_perp = (uv + n * cosTheta) * etaiOverEtat;
    Vector3D r_out_parallel = n * - std::sqrt(fabs(1.0 - r_out_perp.lengthSquared()));
    return r_out_perp + r_out_parallel;
}
