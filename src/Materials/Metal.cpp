/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Metal.cpp
*/

#include "Metal.hpp"

namespace RayTracer {
    Metal::Metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1)
    {
    }

    bool Metal::scatter(const RayTracer::Ray &r_in, const hit_record &rec, color &attenuation,
                        RayTracer::Ray &scattered) const
    {
        Vector3D reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = RayTracer::Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }
}
