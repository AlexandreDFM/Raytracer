/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "AShape.hpp"


namespace RayTracer {
    class Sphere : public AShape {
        public:
            Sphere(const Math::Point3D& origin, double radius);
            bool hits(Ray ray) override;

            Math::Point3D origin;
            double radius;
    };
}

extern "C" RayTracer::Sphere *entryPoint(const Math::Point3D& origin, double radius);
extern "C" char *getType();

#endif /* !SPHERE_HPP_ */
