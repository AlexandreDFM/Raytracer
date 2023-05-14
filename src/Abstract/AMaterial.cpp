/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

namespace RayTracer {
    bool AMaterial::scatter(const RayTracer::Ray &r_in, const RayTracer::hitRecord &rec, color &attenuation,
    RayTracer::Ray &scattered) const
    {
        return false;
    }

    color AMaterial::emitted(double u, double v, const point3 &p) const
    {
        return color(0, 0, 0);
    }
}
