/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** APrimitive.cpp
*/

#include "APrimitive.hpp"

namespace RayTracer {
    bool APrimitive::hit(const RayTracer::Ray &r, double t_min, double t_max, RayTracer::hitRecord &rec) const
    {
        return false;
    }

    bool APrimitive::boundingBox(double time0, double time1, AxisAlignedBoundBox& output_box) const
    {
        return false;
    }
}
