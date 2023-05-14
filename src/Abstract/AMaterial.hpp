/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.hpp
*/

#ifndef AMATERIAL
	#define AMATERIAL

    #include "IMaterial.hpp"

namespace RayTracer {
    class AMaterial : public IMaterial {
        public:
            bool scatter(const RayTracer::Ray & r_in, const RayTracer::hitRecord& rec, color& attenuation, RayTracer::Ray& scattered) const override;
            color emitted(double u, double v, const point3& p) const override;
    };
}

#endif /*AMATERIAL*/
