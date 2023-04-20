/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class Sphere {
        public:
            Sphere(Math::Point3D origin, double radius);
            ~Sphere();
            bool hits(Ray ray);
        Math::Point3D origin;
        double radius;
    };

}
#endif /* !SPHERE_HPP_ */
