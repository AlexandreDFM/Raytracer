/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DiffuseLight.cpp
*/

#include "DiffuseLight.hpp"

namespace RayTracer {
    DiffuseLight::DiffuseLight(const color &a) : emit(a) {}

    bool DiffuseLight::scatter(const Ray &r_in, const hitRecord &rec, color &attenuation, Ray &scattered) const {
        return false;
    }

    color DiffuseLight::emitted(double u, double v, const point3 &p) const {
        return emit;
    }
}

extern "C" {
    RayTracer::DiffuseLight *entryPoint(const color &a, double f) {
        return new RayTracer::DiffuseLight(a);
    }

    char *getType() {
        return (char *) "material_diffuse_light";
    }
}
