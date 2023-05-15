/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SolidColorTexture.hpp
*/
#ifndef SOLIDCOLOR
	#define SOLIDCOLOR

    #include "ITexture.hpp"

namespace RayTracer {
    class SolidColorTexture : public ITexture {
        public:
            SolidColorTexture() = default;
            explicit SolidColorTexture(Color3D c);
            SolidColorTexture(double red, double green, double blue);
            [[nodiscard]] Color3D value(double u, double v, const Vector3D &p) const override;

        private:
            Color3D colorValue;
    };
}


#endif /*SOLIDCOLOR*/
