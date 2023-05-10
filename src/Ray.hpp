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
    class ray {
        public:
            ray() {}
            ray(const point3& origin, const Vector3D& direction)
                : orig(origin), dir(direction)
            {}

            point3 origin() const  { return orig; }
            Vector3D direction() const { return dir; }

            point3 at(double t) const {
                return orig + t*dir;
            }

        public:
            point3 orig;
            Vector3D dir;
    };
}

#endif