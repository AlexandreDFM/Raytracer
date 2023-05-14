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

    Vector3D ALight::getDirection(const point3 &point) const
    {
        return {0, 0, 0};
    }

    color ALight::getColor() const
    {
        return {0, 0, 0};
    }
}
