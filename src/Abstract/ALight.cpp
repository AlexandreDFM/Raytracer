/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ALight.cpp
*/

#include "ALight.hpp"

namespace RayTracer {
    Vector3D ALight::getPosition() const
    {
        return {0, 0, 0};
    }

    Vector3D ALight::getDirection(const Point3D &point) const
    {
        return {0, 0, 0};
    }

    Color3D ALight::getColor() const
    {
        return {0, 0, 0};
    }
}
