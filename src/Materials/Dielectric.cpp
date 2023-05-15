/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Dielectric.cpp
*/

#include "Dielectric.hpp"

namespace RayTracer {
    Dielectric::Dielectric(double indexOfRefraction) : ir(indexOfRefraction)
    {
    }

    bool Dielectric::scatter(const RayTracer::Ray &r_in, const RayTracer::hitRecord &rec, Color3D &attenuation,
                             RayTracer::Ray &scattered) const
    {
        attenuation = Color3D(1.0, 1.0, 1.0);
        double refractionRatio = rec.front_face ? (1.0 / ir) : ir;

        Vector3D v = r_in.direction();
        Vector3D unitDirection = Vector3D::unitVector(v);
        double cosTheta = fmin(Vector3D::dot(-unitDirection, rec.normal), 1.0);
        double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

        bool cannot_refract = refractionRatio * sinTheta > 1.0;
        Vector3D direction;

        if (cannot_refract || reflectance(cosTheta, refractionRatio) > Math::random_double())
            direction = Vector3D::reflect(unitDirection, rec.normal);
        else
            direction = Vector3D::refract(unitDirection, rec.normal, refractionRatio);

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
        Dielectric *entryPoint(const Color3D &a, double f)
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
