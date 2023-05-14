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
            Vector3D getPosition() const override;
            Vector3D getDirection(const point3& point) const override;
            color getColor() const override;
    };
}

#endif /*ALIGHT*/
