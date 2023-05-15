/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CheckerTexture.hpp
*/

#ifndef CHECKERTEXTURE
	#define CHECKERTEXTURE

    #include "SolidColorTexture.hpp"

namespace RayTracer {
    class CheckerTexture : public ITexture {
        public:
            CheckerTexture() = default;
            CheckerTexture(std::shared_ptr<ITexture> _even, std::shared_ptr<ITexture> _odd);
            CheckerTexture(Color3D c1, Color3D c2);
            [[nodiscard]] Color3D value(double u, double v, const Point3D & p) const override;
        public:
            std::shared_ptr<ITexture> odd;
            std::shared_ptr<ITexture> even;
    };

    extern "C" {
        ITexture *textureEntryPoint(std::vector<double> variables);
        char *textureGetType();
    }
}

#endif /*CHECKERTEXTURE*/
