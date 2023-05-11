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
    return Vector3D(-e[0], -e[1], -e[2]);
}

double Vector3D::operator[](int i) const { return e[i]; }

double &Vector3D::operator[](int i) { return e[i]; }

Vector3D &Vector3D::operator+=(const Vector3D &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vector3D &Vector3D::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vector3D &Vector3D::operator/=(const double t) {
    return *this *= 1 / t;
}

double Vector3D::length() const {
    return std::sqrt(length_squared());
}

double Vector3D::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

bool Vector3D::near_zero() const {
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}
