/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Ray
*/

#include "Ray.hpp"

namespace RayTracer {
    Ray::Ray()
    {
    }

    Ray::Ray(Math::Point3D origin, Math::Vector3D direction)
    {
        this->origin.x = origin.x;
        this->origin.y = origin.y;
        this->origin.z = origin.z;
        this->direction.x = direction.x;
        this->direction.y = direction.y;
        this->direction.z = direction.z;
    }

    Ray::Ray(const Ray &other)
    {
        this->origin.x = other.origin.x;
        this->origin.y = other.origin.y;
        this->origin.z = other.origin.z;
        this->direction.x = other.direction.x;
        this->direction.y = other.direction.y;
        this->direction.z = other.direction.z;
    }

    Ray::Ray(const Ray &&other)
    {
        Ray tmp(std::move(other.origin), std::move(other.direction));
    }

    Ray::~Ray()
    {
    }

    Ray Ray::operator+(const Ray &other)
    {
        return Ray(Math::Point3D(this->origin.x + other.origin.x, this->origin.y + other.origin.y, this->origin.z + other.origin.z),
                   Math::Vector3D(this->direction.x + other.direction.x, this->direction.y + other.direction.y, this->direction.z + other.direction.z));
    }

    Ray Ray::operator+=(const Ray &other)
    {
        this->origin.x += other.origin.x;
        this->origin.y += other.origin.y;
        this->origin.z += other.origin.z;
        this->direction.x += other.direction.x;
        this->direction.y += other.direction.y;
        this->direction.z += other.direction.z;
        return *this;
    }
}

//Design patern / Factory / Interface / Archi!!!! /PPM /
