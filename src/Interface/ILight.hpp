/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight.hpp
*/
#ifndef ILIGHT_HPP_
	#define ILIGHT_HPP_

#include "Math/Math.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class ILight {
        public:
            virtual ~ILight() = default;
            virtual Vector3D getPosition() const = 0;
            virtual Vector3D getDirection(const point3& point) const = 0;
            virtual color getColor() const = 0;
    };
}

#endif /*ILIGHT_HPP_*/
