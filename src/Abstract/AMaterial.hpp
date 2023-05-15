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
            bool scatter(const RayTracer::Ray & r_in, const RayTracer::hitRecord& rec, Color3D& attenuation, RayTracer::Ray& scattered) const override;
            [[nodiscard]] Color3D emitted(double u, double v, const Point3D& p) const override;
    };
}

#endif /*AMATERIAL*/
