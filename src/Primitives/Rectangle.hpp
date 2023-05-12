/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Recatngle.hpp
*/

#ifndef Rectangle_HPP_
	#define Rectangle_HPP_

#include "Ray.hpp"
#include "IShape.hpp"
#include "../Math/AxisAlignement.hpp"

namespace RayTracer {
    class Rectangle : public IShape {
    public:
        Rectangle() {}

        Rectangle(double _x0, double _x1, double _y0, double _y1, double _k,
            std::shared_ptr<IMaterial> mat)
            : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), mp(mat) {};

        virtual bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const override;

        virtual bool bounding_box(double time0, double time1, AxisAlignedBoundBox& output_box) {
            // The bounding box must have non-zero width in each dimension, so pad the Z
            // dimension a small amount.
            output_box = AxisAlignedBoundBox(point3(x0,y0, k-0.0001), point3(x1, y1, k+0.0001));
            return true;
        }

        std::shared_ptr<IMaterial> mp;
        double x0, x1, y0, y1, k;
    };

    bool Rectangle::hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const {
        auto t = (k-r.origin().z()) / r.direction().z();
        if (t < t_min || t > t_max)
            return false;
        auto x = r.origin().x() + t*r.direction().x();
        auto y = r.origin().y() + t*r.direction().y();
        if (x < x0 || x > x1 || y < y0 || y > y1)
            return false;
        rec.u = (x-x0)/(x1-x0);
        rec.v = (y-y0)/(y1-y0);
        rec.t = t;
        auto outward_normal = Vector3D(0, 0, 1);
        rec.set_face_normal(r, outward_normal);
        rec.mat_ptr = mp;
        rec.p = r.at(t);
        return true;
    }

}

#endif /*Rectangle_HPP_*/
