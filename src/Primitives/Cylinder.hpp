/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder.hpp
*/
#ifndef CYLINDER_HPP_
	#define CYLINDER_HPP_

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "APrimitive.hpp"
#include "Math/AxisAlignement.hpp"

namespace RayTracer {
    class Cylinder : public APrimitive {
    public:
        Cylinder(double _radius, double _y0, double _y1, const Vector3D& _position, std::shared_ptr<IMaterial> &_mat);
        bool hit(const RayTracer::Ray& r, double t_min, double t_max, hitRecord& rec) const override;
        bool boundingBox(double time0, double time1, AxisAlignedBoundBox& output_box);

    public:
        Vector3D position;
        std::shared_ptr<IMaterial> mat_ptr;
        double radius;
        double y0, y1;
    };

    extern "C" {
        IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &mat_ptr);
        char *getType();
    }
}




#endif /*CYLINDER_HPP_*/
