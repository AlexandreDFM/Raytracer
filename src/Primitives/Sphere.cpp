/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere(point3 cen, double r, std::shared_ptr<IMaterial> m)
            : center(cen), radius(r), mat_ptr(m)
    {
    };

    extern "C" {
        IPrimitive *entryPoint(point3 center, double radius, std::shared_ptr<RayTracer::IMaterial> mat_ptr)
        {
            return new RayTracer::Sphere(center, radius, mat_ptr);
        }

        char *getType()
        {
            return (char *)"primitive_sphere";
        }
    }
}
