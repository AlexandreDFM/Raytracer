/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Sphere
*/

#ifndef SPHERE_H
    #define SPHERE_H

#include "Ray.hpp"
#include "IShape.hpp"

namespace RayTracer {
    class Sphere : public IShape {
        public:
            Sphere() {};
            Sphere(point3 cen, double r, std::shared_ptr<IMaterial> m)
                    : center(cen), radius(r), mat_ptr(m) {};
            virtual bool hit(
                    const RayTracer::Ray &r, double t_min, double t_max, hit_record &rec) const override;
            point3 center;
            double radius;
            std::shared_ptr<IMaterial> mat_ptr;
    };

    inline bool Sphere::hit(const RayTracer::Ray &r, double t_min, double t_max, hit_record &rec) const {
        Vector3D oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
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
}
//extern "C" Sphere *entryPoint(const Math::Point3D& origin, double radius);
extern "C" char *getType();

#endif /* SPHERE_H */
