/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DiffuseLight.hpp
*/
#ifndef DIFFUSELIGHT_HPP_
	#define DIFFUSELIGHT_HPP_

    #include "IMaterial.hpp"

namespace RayTracer {
    class DiffuseLight : public IMaterial {
        public:
            color emit;

            DiffuseLight(const color& a);

            virtual bool scatter(const Ray& r_in, const hitRecord& rec, color& attenuation, Ray& scattered) const override;

            virtual color emitted(double u, double v, const point3& p) const override;
    };
}

extern "C" {
    RayTracer::DiffuseLight *entryPoint(const color &a, double f);
    char *getType();
}

#endif /*DIFFUSELIGHT_HPP_*/
