/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Metal.cpp
*/

#include "Metal.hpp"

namespace RayTracer {
    Metal::Metal(const Color3D& a, double f) : albedo(a), fuzz(f < 1 ? f : 1)
    {
    }

    bool Metal::scatter(const RayTracer::Ray &r_in, const hitRecord &rec, Color3D &attenuation,
                        RayTracer::Ray &scattered) const
    {
        Vector3D v = r_in.direction();
        Vector3D reflected = Vector3D::reflect(Vector3D::unitVector(v), rec.normal);
        scattered = RayTracer::Ray(rec.p, reflected + Vector3D::randomInUnitSphere() * fuzz);
        attenuation = albedo;
        return (Vector3D::dot(scattered.direction(), rec.normal) > 0);
    }

    extern "C" {
        Metal *entryPoint(const Color3D &a, double f)
        {
            return new RayTracer::Metal(a, f);
        }

        char *getType()
        {
            return (char *)"material_metal";
        }
    }
}

