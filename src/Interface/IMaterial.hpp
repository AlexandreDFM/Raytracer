/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef IMATERIAL
	#define IMATERIAL

    #include "Ray.hpp"
    #include "IPrimitive.hpp"
    #include "Math/Math.hpp"

namespace RayTracer {
    class IMaterial {
        public:
            virtual ~IMaterial() = default;
            virtual bool scatter(const RayTracer::Ray & r_in, const RayTracer::hitRecord& rec, Color3D& attenuation, RayTracer::Ray& scattered) const = 0;
            [[nodiscard]] virtual Color3D emitted(double u, double v, const Point3D& p) const = 0;
    };
}

#endif /*IMATERIAL*/
