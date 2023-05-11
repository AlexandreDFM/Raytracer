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

    bool Dielectric::scatter(const RayTracer::Ray &r_in, const RayTracer::hit_record &rec, color &attenuation,
                             RayTracer::Ray &scattered) const
    {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

        Vector3D unit_direction = unit_vector(r_in.direction());
        double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        Vector3D direction;

        if (cannot_refract || reflectance(cos_theta, refraction_ratio) > Math::random_double())
            direction = reflect(unit_direction, rec.normal);
        else
            direction = refract(unit_direction, rec.normal, refraction_ratio);

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
}
