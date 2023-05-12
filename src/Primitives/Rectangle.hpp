/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Recatngle.hpp
*/

#ifndef Rectangle_HPP_
	#define Rectangle_HPP_

#include "Ray.hpp"
#include "IPrimitive.hpp"
#include "../Math/AxisAlignement.hpp"

namespace RayTracer {
    class Rectangle : public IPrimitive {
    public:
        Rectangle(double _x0, double _x1, double _y0, double _y1, double _k, std::shared_ptr<IMaterial> mat);

        virtual bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const override;

        virtual bool bounding_box(double time0, double time1, AxisAlignedBoundBox& output_box);

        std::shared_ptr<IMaterial> mp;
        double x0, x1, y0, y1, k;
    };
}

extern "C" {
    RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr);
    char *getType();
}

#endif /*Rectangle_HPP_*/
