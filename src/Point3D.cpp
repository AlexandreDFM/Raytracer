/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace Math {
    Point3D::Point3D()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Point3D::~Point3D()
    {
    }

    Point3D::Point3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Point3D::Point3D(const Point3D &other)
    {
        Point3D tmp(other.x, other.y, other.z);
    }

    Point3D::Point3D(const Point3D &&other)
    {
        Point3D tmp(std::move(other.x), std::move(other.y), std::move(other.z));
    }

    Point3D Point3D::operator+(const Vector3D &other)
    {
        return Point3D(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    Point3D Point3D::operator+=(const Vector3D &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Point3D Point3D::operator-(const Vector3D &other)
    {
        return Point3D(this->x - other.x, this->y - other.y, this->z - other.z);
    }

}
