/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight.hpp
*/
#ifndef ILIGHT_HPP_
	#define ILIGHT_HPP_

    #include "Ray.hpp"
    #include "Vector3D.hpp"
    #include "Math/Math.hpp"

namespace RayTracer {
    class ILight {
        public:
            virtual ~ILight() = default;
            virtual Vector3D getPosition() const = 0;
            virtual Vector3D getDirection(const Point3D& point) const = 0;
            virtual Color3D getColor() const = 0;
    };
}

#endif /*ILIGHT_HPP_*/
