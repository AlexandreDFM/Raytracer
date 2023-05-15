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
            Ray(const Point3D& origin, const Vector3D& direction);
            [[nodiscard]] Point3D origin() const;
            [[nodiscard]] Vector3D direction() const;
            [[nodiscard]] Point3D at(double t) const;

        public:
            Point3D orig;
            Vector3D dir;
    };
}

#endif
