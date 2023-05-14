/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Lambertian.cpp
*/

#include "Lambertian.hpp"

namespace RayTracer {
    Lambertian::Lambertian(const color &a) : albedo(a)
    {
    }

    bool Lambertian::scatter(const RayTracer::Ray &r_in, const hitRecord &rec, color &attenuation,
                             RayTracer::Ray &scattered) const
    {
        auto scatter_direction = rec.normal + Vector3D::randomUnitVector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

        scattered = RayTracer::Ray(rec.p, scatter_direction);
        attenuation = this->albedo;
        return true;
    }
    extern "C" {
        Lambertian *entryPoint(const color &a, double f)
        {
            (void) f;
            return new Lambertian(a);
        }

        char *getType()
        {
            return (char *)"material_lambertian";
        }
    }

}

