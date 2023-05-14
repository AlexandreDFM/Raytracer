/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Dielectric.cpp
*/

#include "Dielectric.hpp"

namespace RayTracer {
    Dielectric::Dielectric(double index_of_refraction) : ir(index_of_refraction)
    {
    }

    bool Dielectric::scatter(const RayTracer::Ray &r_in, const RayTracer::hitRecord &rec, color &attenuation,
                             RayTracer::Ray &scattered) const
    {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

        Vector3D unit_direction = Vector3D::unitVector(r_in.direction());
        double cos_theta = fmin(Vector3D::dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        Vector3D direction;

        if (cannot_refract || reflectance(cos_theta, refraction_ratio) > Math::random_double())
            direction = Vector3D::reflect(unit_direction, rec.normal);
        else
            direction = Vector3D::refract(unit_direction, rec.normal, refraction_ratio);

        scattered = Ray(rec.p, direction);
        return true;
    }

    double Dielectric::reflectance(double cosine, double ref_idx)
    {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1-ref_idx) / (1+ref_idx);
        r0 = r0*r0;
        return r0 + (1-r0)*pow((1 - cosine),5);
    }

    extern "C" {
        Dielectric *entryPoint(const color &a, double f)
        {
            (void) a;
             return new Dielectric(f);
        }

        char *getType()
        {
            return (char *)"material_dielectric";
        }
    }
}
