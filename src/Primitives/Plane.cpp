/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer {

    Plane::Plane(point3 pos, double radius, std::shared_ptr<IMaterial> m): center(pos), mat_ptr(m)
    {
    }

    extern "C" {
        IPrimitive *entryPoint(point3 center, double radius, std::shared_ptr<RayTracer::IMaterial> mat_ptr)
        {
            return new RayTracer::Plane(center, radius, mat_ptr);
        }

        char *getType()
        {
            return (char *)"primitive_plane";
        }
    }
}
