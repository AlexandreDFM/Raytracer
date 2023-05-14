/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Ray
*/

#ifndef RAY_H
    #define RAY_H

#include "Vector3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            Ray() = default;
            Ray(const point3& origin, const Vector3D& direction);
            point3 origin() const;
            Vector3D direction() const;
            point3 at(double t) const;

        public:
            point3 orig;
            Vector3D dir;
    };
}

#endif
