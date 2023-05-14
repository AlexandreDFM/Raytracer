/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere(point3 cen, double r, std::shared_ptr<IMaterial> &m) : center(cen), radius(r), mat_ptr(m)
    {
    };

    bool Sphere::hit(const RayTracer::Ray &r, double t_min, double t_max, hitRecord &rec) const {
        Vector3D oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = Vector3D::dot(oc, r.direction());
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = half_b * half_b - a * c;
        if (discriminant < 0) return false;
        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (root < t_min || t_max < root) {
            root = (-half_b + sqrtd) / a;
            if (root < t_min || t_max < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vector3D outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat_ptr = mat_ptr;
        return true;
    }

    extern "C" {
        IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &mat_ptr)
        {
            return new RayTracer::Sphere(center, variables[0], mat_ptr);
        }

        char *getType()
        {
            return (char *)"primitive_sphere";
        }
    }
}
