/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

namespace RayTracer {
    Rectangle::Rectangle(double _x0, double _x1, double _y0, double _y1, double _k, std::shared_ptr<IMaterial> mat)
    {
        x0 = _x0;
        x1 = _x1;
        y0 = _y0;
        y1 = _y1;
        k = _k;
        mp = mat;
    }

    bool Rectangle::bounding_box(double time0, double time1, AxisAlignedBoundBox &output_box) {
        // The bounding box must have non-zero width in each dimension, so pad the Z
        // dimension a small amount.
        output_box = AxisAlignedBoundBox(point3(x0,y0, k-0.0001), point3(x1, y1, k+0.0001));
        return true;
    }

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

    /////////////////////////// XZ Rectangle

    xz_rect::xz_rect(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat)
    {
        x0 = _x0;
        x1 = _x1;
        z0 = _z0;
        z1 = _z1;
        k = _k;
        mp = mat;
    }

    bool xz_rect::bounding_box(double time0, double time1, AxisAlignedBoundBox &output_box) {
        // The bounding box must have non-zero width in each dimension, so pad the Z
        // dimension a small amount.
        output_box = AxisAlignedBoundBox(point3(x0,k-0.0001,z0), point3(x1, k+0.0001, z1));
        return true;
    }

    bool xz_rect::hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const {
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

    /////////////////////////// YZ Rectangle

    yz_rect::yz_rect(double _y0, double _y1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat)
    {
        y0 = _y0;
        y1 = _y1;
        z0 = _z0;
        z1 = _z1;
        k = _k;
        mp = mat;
    }

    bool yz_rect::bounding_box(double time0, double time1, AxisAlignedBoundBox &output_box) {
        // The bounding box must have non-zero width in each dimension, so pad the Z
        // dimension a small amount.
        output_box = AxisAlignedBoundBox(point3(k-0.0001,y0,z0), point3(k+0.0001, y1, z1));
        return true;
    }

    bool yz_rect::hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const {
        auto t = (k-r.origin().x()) / r.direction().x();
        if (t < t_min || t > t_max)
            return false;
        auto y = r.origin().y() + t*r.direction().y();
        auto z = r.origin().z() + t*r.direction().z();
        if (y < y0 || y > y1 || z < z0 || z > z1)
            return false;
        rec.u = (y-y0)/(y1-y0);
        rec.v = (z-z0)/(z1-z0);
        rec.t = t;
        auto outward_normal = Vector3D(1, 0, 0);
        rec.set_face_normal(r, outward_normal);
        rec.mat_ptr = mp;
        rec.p = r.at(t);
        return true;
    }

}

extern "C" {
    RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr)
    {
        (void) center;
        return new RayTracer::Rectangle(variables[0], variables[1], variables[2], variables[3], variables[4], mat_ptr);
    }

    char *getType()
    {
        return (char *)"primitive_rectangle";
    }
}
