/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** NoiseTexture.cpp
*/

#include "NoiseTexture.hpp"

namespace RayTracer {
    NoiseTexture::NoiseTexture(double sc) : scale(sc)
    {
    }

    Color3D NoiseTexture::value(double u, double v, const Point3D &p) const
    {
        return Color3D(1, 1, 1) * 0.5 * (1 + sin(scale * p.z() + 10 * noise.turb(p)));
    }

    extern "C" {
        ITexture *entryPoint(std::vector<double> variables)
        {
            return new RayTracer::NoiseTexture(variables[0]);
        }

        char *getType()
        {
            return (char *)"texture_noise";
        }
    }
}
