/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone.cpp
*/

#include "Cone.hpp"

namespace RayTracer {
    Cone::Cone(double _radius, double _height, const Vector3D& _position, std::shared_ptr<IMaterial> _mat)
            : position(_position), radius(_radius), height(_height), mat_ptr(_mat)
    {}

    bool Cone::hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const {
        auto oc = r.origin() - position;
        auto dir = r.direction();

        // Calculate coefficients of the quadratic equation
        auto k = radius / height;
        auto k_squared = k * k;
        auto a = dir.x() * dir.x() + dir.z() * dir.z() - k_squared * dir.y() * dir.y();
        auto b = 2.0 * (oc.x() * dir.x() + oc.z() * dir.z() - k_squared * oc.y() * dir.y());
        auto c = oc.x() * oc.x() + oc.z() * oc.z() - k_squared * oc.y() * oc.y();

        auto discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return false;

        auto sqrt_discriminant = std::sqrt(discriminant);

        // Check for intersection with the cone surface
        auto root = (-b - sqrt_discriminant) / (2.0 * a);
        if (root < t_min || t_max < root) {
            root = (-b + sqrt_discriminant) / (2.0 * a);
            if (root < t_min || t_max < root)
                return false;
        }

        // Calculate hit point and check if it's within the height of the cone
        auto hit_point = r.at(root);
        if (hit_point.y() < 0 || hit_point.y() > height)
            return false;

        rec.t = root;
        rec.p = hit_point;
        rec.mat_ptr = mat_ptr;

        // Compute the outward normal based on the hit point
        if (hit_point.y() < k * hit_point.x() + height && hit_point.y() < -k * hit_point.x() + height) {
            // Intersection with the side of the cone
            auto outward_normal = Vector3D(hit_point.x(), k * hit_point.y(), hit_point.z());
            rec.set_face_normal(r, outward_normal);
        } else {
            // Intersection with the base of the cone
            auto outward_normal = Vector3D(0, -1, 0);
            rec.set_face_normal(r, outward_normal);
        }

        return true;
    }

    bool Cone::bounding_box(double time0, double time1, AxisAlignedBoundBox& output_box) {
        // Calculate the bounding box of the cone + its base
        auto radius_vec = Vector3D(radius, 0, radius);
        auto min = position - radius_vec;
        auto max = position + radius_vec + Vector3D(0, height, 0);

        output_box = AxisAlignedBoundBox(min, max);

        return true;
    }
}

extern "C" RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr)
{
    (void) center;
    return new RayTracer::Cone(variables[0], variables[1], center, mat_ptr);
}

extern "C" char *getType()
{
    return (char *)"primitive_cone";
}
