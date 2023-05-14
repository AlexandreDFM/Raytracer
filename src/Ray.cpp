/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray.cpp
*/

#include "Ray.hpp"

namespace RayTracer {
    Ray::Ray(const point3& origin, const Vector3D& direction) : orig(origin), dir(direction)
    {
    }

    point3 Ray::origin() const
    {
        return orig;
    }

    Vector3D Ray::direction() const
    {
        return dir;
    }

    point3 Ray::at(double t) const
    {
        return orig + t * dir;
    }
}
