/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Metal.hpp
*/

#ifndef METAL_
	#define METAL_

    #include "AMaterial.hpp"

namespace RayTracer {
    class Metal : public AMaterial {
        public:
            Metal(const color& a, double f);

            virtual bool scatter(const RayTracer::Ray& r_in, const hitRecord& rec, color& attenuation, RayTracer::Ray& scattered) const override;

        public:
            color albedo;
            double fuzz;
    };

    extern "C" {
        Metal *entryPoint(const color &a, double f);
        char *getType();
    }
}


#endif /*METAL_*/
