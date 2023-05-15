/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CheckerTexture.cpp
*/

#include "CheckerTexture.hpp"

namespace RayTracer {
    CheckerTexture::CheckerTexture(std::shared_ptr<ITexture> even, std::shared_ptr<ITexture> odd)
    : even(even), odd(odd)
    {
    }

    CheckerTexture::CheckerTexture(Color3D c1, Color3D c2) : even(std::make_shared<SolidColorTexture>(c1)), odd(std::make_shared<SolidColorTexture>(c2))
    {
    }

    Color3D CheckerTexture::value(double u, double v, const Point3D &p) const
    {
        auto sines = sin(10 * p.x()) * sin(10 * p.y()) * sin(10 * p.z());
        if (sines < 0)
            return odd->value(u, v, p);
        else
            return even->value(u, v, p);
    }

    extern "C" {
        ITexture *entryPoint(std::vector<double> variables)
        {
            return new CheckerTexture(Color3D(variables[0], variables[1], variables[2]), Color3D(variables[3], variables[4], variables[5]));
        }

        char *getType()
        {
            return (char *)"texture_checker";
        }
    }
}
