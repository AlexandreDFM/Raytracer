/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

namespace RayTracer {
    Rectangle::Rectangle(double _x0, double _x1, double _y0, double _y1, double _k, const Vector3D &_position, std::shared_ptr<IMaterial> &mat)
            : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), position(_position), mp(mat)
    {
    }

    bool Rectangle::boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox) {
        // The bounding box must have non-zero width in each dimension, so pad the Z
        // dimension a small amount.
        outputBox = AxisAlignedBoundBox(
                Point3D(x0, y0, k - 0.0001) + position,
                Point3D(x1, y1, k + 0.0001) + position
        );
        return true;
    }

    bool Rectangle::hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const {
        auto t = (k - (r.origin().z() - position.z())) / r.direction().z();
        if (t < tMin || t > tMax)
            return false;
        auto x = r.origin().x() + t * r.direction().x() - position.x();
        auto y = r.origin().y() + t * r.direction().y() - position.y();
        if (x < x0 || x > x1 || y < y0 || y > y1)
            return false;
        rec.u = (x - x0) / (x1 - x0);
        rec.v = (y - y0) / (y1 - y0);
        rec.t = t;
        auto outward_normal = Vector3D(0, 0, 1);
        rec.set_face_normal(r, outward_normal);
        rec.matPtr = mp;
        rec.p = r.at(t);
        return true;
    }

    /////////////////////////// XZ Rectangle

    xzRect::xzRect(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> &mat)
    {
        x0 = _x0;
        x1 = _x1;
        z0 = _z0;
        z1 = _z1;
        k = _k;
        mp = mat;
    }

    bool xzRect::boundingBox(double time0, double time1, AxisAlignedBoundBox &outputBox) {
        // The bounding box must have non-zero width in each dimension, so pad the Z
        // dimension a small amount.
        outputBox = AxisAlignedBoundBox(Point3D(x0,k-0.0001,z0), Point3D(x1, k+0.0001, z1));
        return true;
    }

    bool xzRect::hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const {
        auto t = (k-r.origin().y()) / r.direction().y();
        if (t < tMin || t > tMax)
            return false;
        auto x = r.origin().x() + t * r.direction().x();
        auto z = r.origin().z() + t * r.direction().z();
        if (x < x0 || x > x1 || z < z0 || z > z1)
            return false;
        rec.u = (x - x0) / (x1 - x0);
        rec.v = (z - z0) / (z1 - z0);
        rec.t = t;
        auto outward_normal = Vector3D(0, 1, 0);
        rec.set_face_normal(r, outward_normal);
        rec.matPtr = mp;
        rec.p = r.at(t);
        return true;
    }

    /////////////////////////// YZ Rectangle

    yzRect::yzRect(double _y0, double _y1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> &mat)
    {
        y0 = _y0;
        y1 = _y1;
        z0 = _z0;
        z1 = _z1;
        k = _k;
        mp = mat;
    }

    bool yzRect::boundingBox(double time0, double time1, AxisAlignedBoundBox &outputBox) {
        // The bounding box must have non-zero width in each dimension, so pad the Z
        // dimension a small amount.
        outputBox = AxisAlignedBoundBox(Point3D(k-0.0001,y0,z0), Point3D(k+0.0001, y1, z1));
        return true;
    }

    bool yzRect::hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const {
        auto t = (k - r.origin().x()) / r.direction().x();
        if (t < tMin || t > tMax)
            return false;
        auto y = r.origin().y() + t * r.direction().y();
        auto z = r.origin().z() + t * r.direction().z();
        if (y < y0 || y > y1 || z < z0 || z > z1)
            return false;
        rec.u = (y - y0) / (y1 - y0);
        rec.v = (z - z0) / (z1 - z0);
        rec.t = t;
        auto outward_normal = Vector3D(1, 0, 0);
        rec.set_face_normal(r, outward_normal);
        rec.matPtr = mp;
        rec.p = r.at(t);
        return true;
    }

}

extern "C" {
    RayTracer::IPrimitive *entryPoint(Point3D &center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> matPtr)
    {
        (void) center;
        return new RayTracer::Rectangle(variables[0], variables[1], variables[2], variables[3], variables[4], center, matPtr);
    }

    char *getType()
    {
        return (char *)"primitive_rectangle";
    }
}
