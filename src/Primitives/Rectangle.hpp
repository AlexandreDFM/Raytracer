/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Recatngle.hpp
*/

#ifndef Rectangle_HPP_
	#define Rectangle_HPP_

#include "Ray.hpp"
#include "APrimitive.hpp"
#include "../Math/AxisAlignement.hpp"

namespace RayTracer {
    class Rectangle : public APrimitive {
    public:
        Rectangle(double _x0, double _x1, double _y0, double _y1, double _k, const Vector3D &_position, std::shared_ptr<IMaterial> &mat);
        bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;
        bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox);

        std::shared_ptr<IMaterial> mp;
        double x0, x1, y0, y1, k;
        Vector3D position;
    };


    class xzRect : public IPrimitive {
        public:
            xzRect(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> &mat);
            bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;
            bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox);

        public:
            std::shared_ptr<IMaterial> mp;
            double x0, x1, z0, z1, k;
    };

    class yzRect : public IPrimitive {
        public:
            yzRect(double _y0, double _y1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> &mat);
            bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;
            bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox);

        public:
            std::shared_ptr<IMaterial> mp;
            double y0, y1, z0, z1, k;
    };

}
extern "C" {
    RayTracer::IPrimitive *entryPoint(Point3D &center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> matPtr);
    char *getType();
}

#endif /*Rectangle_HPP_*/
