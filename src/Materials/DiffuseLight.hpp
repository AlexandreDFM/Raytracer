/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DiffuseLight.hpp
*/
#ifndef DIFFUSELIGHT_HPP_
	#define DIFFUSELIGHT_HPP_

    #include "AMaterial.hpp"

namespace RayTracer {
    class DiffuseLight : public AMaterial {
        public:
            DiffuseLight(const Color3D& a);
            bool scatter(const Ray& r_in, const hitRecord& rec, Color3D& attenuation, Ray& scattered) const override;
            [[nodiscard]] Color3D emitted(double u, double v, const Point3D& p) const override;

        public:
            Color3D emit;
    };
}

extern "C" {
    RayTracer::DiffuseLight *entryPoint(const Color3D &a, double f);
    char *getType();
}

#endif /*DIFFUSELIGHT_HPP_*/
