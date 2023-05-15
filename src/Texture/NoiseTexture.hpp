/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** NoiseTexture.hpp
*/
#ifndef NOISETEXTURE
	#define NOISETEXTURE

    #include "Texture/Perlin/Perlin.hpp"
    #include "ITexture.hpp"

namespace RayTracer {
    class NoiseTexture : public ITexture {
        public:
            NoiseTexture() = default;
            explicit NoiseTexture(double sc);
            [[nodiscard]] Color3D value(double u, double v, const Point3D& p) const override;

        public:
            Perlin noise;
            double scale;
    };

    extern "C" {
        ITexture *entryPoint(std::vector<double> variables);
        char *getType();
    }
}

#endif /*NOISETEXTURE*/
