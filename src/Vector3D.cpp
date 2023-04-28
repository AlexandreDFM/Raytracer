/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <cmath>

namespace Math {
    Vector3D::Vector3D()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector3D::Vector3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3D::Vector3D(const Vector3D &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }

    Vector3D::Vector3D(const Vector3D &&other)
    {
        Vector3D tmp(std::move(other.x), std::move(other.y), std::move(other.z));
    }

    Vector3D::~Vector3D()
    {
    }

    double Vector3D::length()
    {
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    Vector3D Vector3D::operator+(const Vector3D &other)
    {
        return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    Vector3D Vector3D::operator+=(const Vector3D &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vector3D Vector3D::operator-(const Vector3D &other)
    {
        return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    Vector3D Vector3D::operator-=(const Vector3D &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Vector3D Vector3D::operator*(const Vector3D &other)
    {
        return Vector3D(this->x * other.x, this->y * other.y, this->z * other.z);
    }

    Vector3D Vector3D::operator*=(const Vector3D &other)
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;
        return *this;
    }

    Vector3D Vector3D::operator/(const Vector3D &other)
    {
        return Vector3D(this->x / other.x, this->y / other.y, this->z / other.z);
    }

    Vector3D Vector3D::operator/=(const Vector3D &other)
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;
        return *this;
    }

    Vector3D Vector3D::operator*(const double &other)
    {
        return Vector3D(this->x * other, this->y * other, this->z * other);
    }

    Vector3D Vector3D::operator*=(const double &other)
    {
        this->x *= other;
        this->y *= other;
        this->z *= other;
        return *this;
    }

    Vector3D Vector3D::operator/(const double &other)
    {
        return Vector3D(this->x / other, this->y / other, this->z / other);
    }

    Vector3D Vector3D::operator/=(const double &other)
    {
        this->x /= other;
        this->y /= other;
        this->z /= other;
        return *this;
    }

    Vector3D Vector3D::operator=(const Vector3D &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        return *this;
    }
    double Vector3D::dot(const Vector3D &other)
    {
        return (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) * sqrt(pow(other.x, 2) + pow(other.y, 2) + pow(other.z, 2)));
    }
}