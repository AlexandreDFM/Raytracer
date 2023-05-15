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
        bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;
        bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox);

    public:
        Vector3D position;
        std::shared_ptr<IMaterial> matPtr;
        double radius;
        double y0, y1;
    };

    extern "C" {
        IPrimitive *entryPoint(Point3D &center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &matPtr);
        char *getType();
    }
}




#endif /*CYLINDER_HPP_*/
