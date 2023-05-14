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

    bool Metal::scatter(const RayTracer::Ray &r_in, const hitRecord &rec, color &attenuation,
                        RayTracer::Ray &scattered) const
    {
        Vector3D reflected = Vector3D::reflect(Vector3D::unitVector(r_in.direction()), rec.normal);
        scattered = RayTracer::Ray(rec.p, reflected + fuzz * Vector3D::randomInUnitSphere());
        attenuation = albedo;
        return (Vector3D::dot(scattered.direction(), rec.normal) > 0);
    }

    extern "C" {
        Metal *entryPoint(const color &a, double f)
        {
            return new RayTracer::Metal(a, f);
        }

        char *getType()
        {
            return (char *)"material_metal";
        }
    }
}

