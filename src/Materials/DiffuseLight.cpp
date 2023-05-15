/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DiffuseLight.cpp
*/

#include "DiffuseLight.hpp"

namespace RayTracer {
    DiffuseLight::DiffuseLight(const Color3D &a) : emit(a)
    {
    }

    bool DiffuseLight::scatter(const Ray &r_in, const hitRecord &rec, Color3D &attenuation, Ray &scattered) const {
        return false;
    }

    Color3D DiffuseLight::emitted(double u, double v, const Point3D &p) const {
        return emit;
    }
}

extern "C" {
    RayTracer::DiffuseLight *entryPoint(const Color3D &a, double f) {
        return new RayTracer::DiffuseLight(a);
    }

    char *getType() {
        return (char *) "material_diffuse_light";
    }
}
