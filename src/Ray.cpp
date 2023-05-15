/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray.cpp
*/

#include "Ray.hpp"

namespace RayTracer {
    Ray::Ray(const Point3D& origin, const Vector3D& direction) : orig(origin), dir(direction)
    {
    }

    Point3D Ray::origin() const
    {
        return orig;
    }

    Vector3D Ray::direction() const
    {
        return dir;
    }

    Point3D Ray::at(double t) const
    {
        return orig + dir * t;
    }
}
