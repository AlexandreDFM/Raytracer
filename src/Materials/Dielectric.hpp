/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Dielectric.hpp
*/

#ifndef DIELECTRIC
	#define DIELECTRIC

    #include "Math/Math.hpp"
    #include "AMaterial.hpp"

namespace RayTracer {
    class Dielectric : public AMaterial {
        public:
            Dielectric(double indexOfRefraction);
            bool scatter(const Ray& r_in, const hitRecord& rec, Color3D& attenuation, Ray& scattered) const override;

        public:
            double ir; // Index of Refraction

        private:
            static double reflectance(double cosine, double ref_idx);
    };

    extern "C" {
        Dielectric *entryPoint(const Color3D &a, double f);
        char *getType();
    }
}

#endif /*DIELECTRIC*/
