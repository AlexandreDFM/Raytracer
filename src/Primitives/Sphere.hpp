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
            Sphere(point3 cen, double r, std::shared_ptr<IMaterial> &m);
            bool hit(const RayTracer::Ray &r, double t_min, double t_max, hitRecord &rec) const override;
        public:
                point3 center;
                double radius;
                std::shared_ptr<IMaterial> mat_ptr;
    };


    extern "C" {
        IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &mat_ptr);
        char *getType();
    }
}

#endif /* SPHERE_H */
