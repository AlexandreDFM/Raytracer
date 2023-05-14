/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Lambertian.hpp
*/

#ifndef LAMBERTIAN_HPP_
	#define LAMBERTIAN_HPP_

    #include "AMaterial.hpp"

namespace RayTracer {
    class Lambertian : public AMaterial {
        public:
            Lambertian(const color &a);
            virtual bool scatter(const RayTracer::Ray &r_in, const hitRecord &rec, color &attenuation, RayTracer::Ray &scattered) const override;
        public:
            color albedo;
    };

    extern "C" {
        Lambertian *entryPoint(const color &a, double f);
        char *getType();
    }
}


#endif /*LAMBERTIAN_HPP_*/
