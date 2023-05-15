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
            Lambertian(const Color3D &a);
            bool scatter(const RayTracer::Ray &r_in, const hitRecord &rec, Color3D &attenuation, RayTracer::Ray &scattered) const override;
        public:
            Color3D albedo;
    };

    extern "C" {
        Lambertian *entryPoint(const Color3D &a, double f);
        char *getType();
    }
}


#endif /*LAMBERTIAN_HPP_*/
