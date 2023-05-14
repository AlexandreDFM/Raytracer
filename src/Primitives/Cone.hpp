/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone.hpp
*/
#ifndef CONE_HPP_
	#define CONE_HPP_

#include "Ray.hpp"
#include "IPrimitive.hpp"
#include "Math/AxisAlignement.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class Cone : public IPrimitive {
    public:
        Cone(double _radius, double _height, const Vector3D& _position, std::shared_ptr<IMaterial> _mat);

        virtual bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const override;

        virtual bool bounding_box(double time0, double time1, AxisAlignedBoundBox& output_box);

    private:
        Vector3D position;
        double radius;
        double height;
        std::shared_ptr<IMaterial> mat_ptr;
    };
}

extern "C" {
    RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr);
    char *getType();
}

#endif /*CONE_HPP_*/
