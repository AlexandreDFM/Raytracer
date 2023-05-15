/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"

namespace RayTracer {
    Cylinder::Cylinder(Point3D baseCenter, double height, double radius, std::shared_ptr<IMaterial>& m)
            : baseCenter(baseCenter), height(height), radius(radius), matPtr(m)
    {
    }

    bool Cylinder::hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const
    {
        Vector3D oc = r.origin() - baseCenter;

        auto a = Vector3D::dot(r.direction(), r.direction()) - Vector3D::dot(r.direction(), Vector3D(0, 1, 0)) * Vector3D::dot(r.direction(), Vector3D(0, 1, 0));
        auto b = 2 * (Vector3D::dot(oc, r.direction()) - Vector3D::dot(oc, Vector3D(0, 1, 0)) * Vector3D::dot(r.direction(), Vector3D(0, 1, 0)));
        auto c = Vector3D::dot(oc, oc) - radius * radius - Vector3D::dot(oc, Vector3D(0, 1, 0)) * Vector3D::dot(oc, Vector3D(0, 1, 0));

        auto discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return false;

        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-b - sqrtd) / (2 * a);
        if (root < tMin || tMax < root) {
            root = (-b + sqrtd) / (2 * a);
            if (root < tMin || tMax < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vector3D outward_normal = (rec.p - baseCenter - Vector3D(0, 1, 0) * (height / 2)) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.matPtr = matPtr;

        return true;
    }

    extern "C" {
    IPrimitive* entryPoint(Point3D baseCenter, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial>& matPtr)
    {
        return new RayTracer::Cylinder(baseCenter, variables[0], variables[1], matPtr);
    }

    char* getType()
    {
        return (char*)"primitive_cylinder";
    }
    }
}
