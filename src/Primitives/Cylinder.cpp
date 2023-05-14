/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"

namespace RayTracer {
    Cylinder::Cylinder(double _radius, double _y0, double _y1, const Vector3D& _position, std::shared_ptr<IMaterial> _mat)
            : radius(_radius), y0(_y0), y1(_y1), position(_position), mat_ptr(_mat) {}

    bool Cylinder::hit(const RayTracer::Ray &r, double t_min, double t_max, RayTracer::hit_record &rec) const {
        auto oc = r.origin() - position;
        auto dir = r.direction();
        auto a = dir.x() * dir.x() + dir.z() * dir.z();
        auto b = 2.0 * (dir.x() * oc.x() + dir.z() * oc.z());
        auto c = oc.x() * oc.x() + oc.z() * oc.z() - radius * radius;

        auto discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return false;

        auto sqrt_discriminant = std::sqrt(discriminant);

        // Check for intersection with the sides of the cylinder
        auto root = (-b - sqrt_discriminant) / (2.0 * a);
        if (root < t_min || t_max < root) {
            root = (-b + sqrt_discriminant) / (2.0 * a);
            if (root < t_min || t_max < root)
                return false;
        }

        // Check for intersection with the top and bottom caps
        auto hit_point = r.at(root);
        if (hit_point.y() < y0 || hit_point.y() > y1) {
            // Check for intersection with the bottom cap
            root = (-oc.y() - y0) / dir.y();
            if (root > t_min && root < t_max) {
                hit_point = r.at(root);
                if (hit_point.x() * hit_point.x() + hit_point.z() * hit_point.z() <= radius * radius) {
                    rec.t = root;
                    rec.p = hit_point;
                    rec.mat_ptr = mat_ptr;
                    auto outward_normal = Vector3D(0, -1, 0);
                    rec.set_face_normal(r, outward_normal);
                    return true;
                }
            }

            // Check for intersection with the top cap
            root = (-oc.y() - y1) / dir.y();
            if (root > t_min && root < t_max) {
                hit_point = r.at(root);
                if (hit_point.x() * hit_point.x() + hit_point.z() * hit_point.z() <= radius * radius) {
                    rec.t = root;
                    rec.p = hit_point;
                    rec.mat_ptr = mat_ptr;
                    auto outward_normal = Vector3D(0, 1, 0);
                    rec.set_face_normal(r, outward_normal);
                    return true;
                }
            }

            // No intersection with the caps or sides of the cylinder
            return false;
        }

        rec.t = root;
        rec.p = hit_point;
        rec.mat_ptr = mat_ptr;

        // Compute the outward normal based on the hit point
        auto outward_normal = Vector3D(hit_point.x(), 0, hit_point.z());
        rec.set_face_normal(r, outward_normal);

        return true;
    }

    bool Cylinder::bounding_box(double time0, double time1, AxisAlignedBoundBox &output_box) {
        output_box = AxisAlignedBoundBox(
                Vector3D(position.x() - radius, y0, position.z() - radius),
                Vector3D(position.x() + radius, y1, position.z() + radius)
        );
        return true;
    }
}

extern "C" {
    RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr)
    {
        return new RayTracer::Cylinder(variables[0], variables[1], variables[2], center, mat_ptr);
    }

    char *getType()
    {
        return (char *)"primitive_cylinder";
    }
}
