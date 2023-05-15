/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

namespace RayTracer {
    bool AMaterial::scatter(const RayTracer::Ray &r_in, const RayTracer::hitRecord &rec, Color3D &attenuation,
    RayTracer::Ray &scattered) const
    {
        return false;
    }

    Color3D AMaterial::emitted(double u, double v, const Point3D &p) const
    {
        return {0, 0, 0};
    }
}
