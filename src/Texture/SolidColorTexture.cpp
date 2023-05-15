/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SolidColorTexture.cpp
*/

#include "SolidColorTexture.hpp"

namespace RayTracer {
    SolidColorTexture::SolidColorTexture(Color3D c) : colorValue(c)
    {
    }

    SolidColorTexture::SolidColorTexture(double red, double green, double blue) : SolidColorTexture(Color3D(red, green, blue))
    {
    }

    Color3D SolidColorTexture::value(double u, double v, const Vector3D& p) const
    {
        return this->colorValue;
    }
}
