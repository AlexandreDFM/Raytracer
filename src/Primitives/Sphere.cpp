/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

extern "C" RayTracer::IShape *entryPoint(point3 center, double radius, std::shared_ptr<RayTracer::IMaterial> mat_ptr)
{
    return new RayTracer::Sphere(center, radius, mat_ptr);
}

extern "C" char *getType()
{
    return (char *)"primitive_sphere";
}
