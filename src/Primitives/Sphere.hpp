/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Sphere
*/

#ifndef SPHERE_H
    #define SPHERE_H

#include "Ray.hpp"
#include "APrimitive.hpp"

namespace RayTracer {
    class Sphere : public APrimitive {
        public:
            Sphere(Point3D cen, double r, std::shared_ptr<IMaterial> &m);
            bool hit(const RayTracer::Ray &r, double tMin, double tMax, hitRecord &rec) const override;
        public:
                Point3D center;
                double radius;
                std::shared_ptr<IMaterial> matPtr;
    };


    extern "C" {
        IPrimitive *entryPoint(Point3D center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &matPtr);
        char *getType();
    }
}

#endif /* SPHERE_H */
