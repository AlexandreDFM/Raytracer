/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ALight.hpp
*/

#ifndef ALIGHT
	#define ALIGHT

    #include "ILight.hpp"

namespace RayTracer {
    class ALight : public ILight {
        public:
            [[nodiscard]] Vector3D getPosition() const override;
            [[nodiscard]] Vector3D getDirection(const Point3D& point) const override;
            [[nodiscard]] Color3D getColor() const override;
    };
}

#endif /*ALIGHT*/
