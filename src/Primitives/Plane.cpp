/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer {
    Plane::Plane(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat)
    {
        x0 = _x0;
        x1 = _x1;
        z0 = _z0;
        z1 = _z1;
        k = _k;
        mp = mat;
    }

    bool Plane::bounding_box(double time0, double time1, AxisAlignedBoundBox &output_box) {
        output_box = AxisAlignedBoundBox(point3(x0,k-0.0001,z0), point3(x1, k+0.0001, z1));
        return true;
    }

    bool Plane::hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const {
        auto t = (k-r.origin().y()) / r.direction().y();
        if (t < t_min || t > t_max)
            return false;
        auto x = r.origin().x() + t*r.direction().x();
        auto z = r.origin().z() + t*r.direction().z();
        if (x < x0 || x > x1 || z < z0 || z > z1)
            return false;
        rec.u = (x-x0)/(x1-x0);
        rec.v = (z-z0)/(z1-z0);
        rec.t = t;
        auto outward_normal = Vector3D(0, 1, 0);
        rec.set_face_normal(r, outward_normal);
        rec.mat_ptr = mp;
        rec.p = r.at(t);
        return true;
    }
}
