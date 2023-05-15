/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Lambertian.cpp
*/

#include "Lambertian.hpp"

namespace RayTracer {
    Lambertian::Lambertian(const Color3D &a) : albedo(std::make_shared<SolidColorTexture>(a))
    {
    }

    Lambertian::Lambertian(std::shared_ptr<ITexture> a) : albedo(a)
    {
    }

    bool Lambertian::scatter(const RayTracer::Ray &r_in, const hitRecord &rec, Color3D &attenuation,
    RayTracer::Ray &scattered) const
    {
        auto scatter_direction = rec.normal + Vector3D::randomUnitVector();

        // Catch degenerate scatter direction
        if (scatter_direction.nearZero())
        scatter_direction = rec.normal;

        scattered = RayTracer::Ray(rec.p, scatter_direction);
        attenuation = this->albedo->value(rec.u, rec.v, rec.p);
        return true;
    }

    extern "C" {
        Lambertian *textureEntryPoint(std::shared_ptr<ITexture> a)
        {
            return new Lambertian(a);
        }

        Lambertian *entryPoint(const Color3D &a, double f)
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

