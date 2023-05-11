/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Metal.hpp
*/

#ifndef METAL_
	#define METAL_

    #include "IMaterial.hpp"

namespace RayTracer {
    class Metal : public IMaterial {
        public:
            Metal(const color& a, double f);

            virtual bool scatter(const RayTracer::Ray& r_in, const hit_record& rec, color& attenuation, RayTracer::Ray& scattered) const override;

        public:
            color albedo;
            double fuzz;
        };
}

extern "C" RayTracer::Metal *entryPoint(const color &a, double f);
extern "C" char *getType();

#endif /*METAL_*/
