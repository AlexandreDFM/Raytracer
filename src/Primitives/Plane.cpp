/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer {
    Plane::Plane(const Vector3D& _normal, double _distance, std::shared_ptr<IMaterial>& _mat)
            : normal(_normal), distance(_distance), mat(_mat) {}

    bool Plane::boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox) {
        // Plane is infinite, so we use large bounding box values
        outputBox = AxisAlignedBoundBox(Point3D(-INFINITY, -INFINITY, -INFINITY), Point3D(INFINITY, INFINITY, INFINITY));
        return false;
    }

    bool Plane::hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const {
        double denominator = Vector3D::dot(normal, r.direction());
        if (denominator == 0) {
            // Ray is parallel to the plane
            return false;
        }

        double t = (distance - Vector3D::dot(normal, r.origin())) / denominator;
        if (t < tMin || t > tMax) {
            // The hit point is outside the valid range
            return false;
        }

        rec.t = t;
        rec.matPtr = mat;
        rec.p = r.at(t);
        rec.set_face_normal(r, normal);

        return true;
    }


    extern "C" {
        RayTracer::IPrimitive *entryPoint(Vector3D &center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> matPtr)
        {
            return new Plane(center, variables[0], matPtr);
        }

        char *getType()
        {
            return (char *)"primitive_plane";
        }
    }
}

