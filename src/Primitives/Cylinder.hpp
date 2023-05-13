/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder.hpp
*/
#ifndef CYLINDER_HPP_
	#define CYLINDER_HPP_

#include "Ray.hpp"
#include "IPrimitive.hpp"
#include "Math/AxisAlignement.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class Cylinder : public IPrimitive {
    public:
        Cylinder(double _radius, double _y0, double _y1, std::shared_ptr<IMaterial> _mat);

        virtual bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const override;

        virtual bool bounding_box(double time0, double time1, AxisAlignedBoundBox& output_box);

    public:
        std::shared_ptr<IMaterial> mat_ptr;
        double radius;
        double y0, y1;
    };
}



extern "C" {
    RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr);
    char *getType();
}

#endif /*CYLINDER_HPP_*/
