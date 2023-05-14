/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"

namespace RayTracer {
    Cylinder::Cylinder(double _radius, double _y0, double _y1, const Vector3D& _position, std::shared_ptr<IMaterial> &_mat)
            : radius(_radius), y0(_y0), y1(_y1), position(_position), mat_ptr(_mat) {}

    bool Cylinder::hit(const RayTracer::Ray& r, double t_min, double t_max, RayTracer::hitRecord& rec) const {
        Vector3D oc = r.origin() - position;

        double a = r.direction().x() * r.direction().x() + r.direction().z() * r.direction().z();
        double b = 2.0 * (oc.x() * r.direction().x() + oc.z() * r.direction().z());
        double c = oc.x() * oc.x() + oc.z() * oc.z() - radius * radius;

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant > 0) {
            double root = (-b - sqrt(discriminant)) / (2.0 * a);
            if (root < t_min || root > t_max) {
                root = (-b + sqrt(discriminant)) / (2.0 * a);
                if (root < t_min || root > t_max) {
                    return false;
                }
            }

            double y = r.origin().y() + root * r.direction().y();
            if (y < y0 || y > y1) {
                return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            Vector3D outward_normal = (rec.p - position) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat_ptr = mat_ptr;

            return true;
        }

        return false;
    }

    bool Cylinder::boundingBox(double time0, double time1, AxisAlignedBoundBox &output_box) {
        output_box = AxisAlignedBoundBox(
                position - Vector3D(radius, y0, radius),
                position + Vector3D(radius, y1, radius)
        );
        return true;
    }

    extern "C" {
        RayTracer::IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &mat_ptr)
        {
            return new Cylinder(variables[0], variables[1], variables[2], center, mat_ptr);
        }

        char *getType()
        {
            return (char *)"primitive_cylinder";
        }
    }
}

