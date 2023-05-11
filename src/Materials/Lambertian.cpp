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

    bool Lambertian::scatter(const RayTracer::Ray &r_in, const hit_record &rec, color &attenuation,
                             RayTracer::Ray &scattered) const
    {
        auto scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

        scattered = RayTracer::Ray(rec.p, scatter_direction);
        attenuation = this->albedo;
        return true;
    }
}
