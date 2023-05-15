/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere(Point3D cen, double r, std::shared_ptr<IMaterial> &m) : center(cen), radius(r), matPtr(m)
    {
    };

    bool Sphere::hit(const RayTracer::Ray &r, double tMin, double tMax, hitRecord &rec) const {
        Vector3D oc = r.origin() - center;
        auto a = r.direction().lengthSquared();
        auto half_b = Vector3D::dot(oc, r.direction());
        auto c = oc.lengthSquared() - radius * radius;

        auto discriminant = half_b * half_b - a * c;
        if (discriminant < 0) return false;
        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (root < tMin || tMax < root) {
            root = (-half_b + sqrtd) / a;
            if (root < tMin || tMax < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vector3D outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.matPtr = matPtr;
        return true;
    }

    extern "C" {
        IPrimitive *entryPoint(Point3D center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &matPtr)
        {
            return new RayTracer::Sphere(center, variables[0], matPtr);
        }

        char *getType()
        {
            return (char *)"primitive_sphere";
        }
    }
}
