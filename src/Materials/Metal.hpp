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
            Metal(const Color3D& a, double f);
            bool scatter(const RayTracer::Ray& r_in, const hitRecord& rec, Color3D& attenuation, RayTracer::Ray& scattered) const override;

        public:
            Color3D albedo;
            double fuzz;
    };

    extern "C" {
        Metal *entryPoint(const Color3D &a, double f);
        char *getType();
    }
}


#endif /*METAL_*/
