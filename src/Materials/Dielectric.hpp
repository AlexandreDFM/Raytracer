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
            Dielectric(double index_of_refraction);

            virtual bool scatter(const Ray& r_in, const hitRecord& rec, color& attenuation, Ray& scattered) const override;

        public:
            double ir; // Index of Refraction

        private:
            static double reflectance(double cosine, double ref_idx);
    };

    extern "C" {
        Dielectric *entryPoint(const color &a, double f);
        char *getType();
    }
}

#endif /*DIELECTRIC*/
