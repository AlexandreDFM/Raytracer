/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"

namespace RayTracer {
    Cylinder::Cylinder(double _radius, double _y0, double _y1, const Vector3D &_position, std::shared_ptr<IMaterial> &_mat)
            : radius(_radius), y0(_y0), y1(_y1), position(_position), matPtr(_mat) {}

    bool Cylinder::hit(const RayTracer::Ray& r, double tMin, double tMax, RayTracer::hitRecord& rec) const {
        Vector3D oc = r.origin() - position;

        double a = r.direction().x() * r.direction().x() + r.direction().z() * r.direction().z();
        double b = 2.0 * (oc.x() * r.direction().x() + oc.z() * r.direction().z());
        double c = oc.x() * oc.x() + oc.z() * oc.z() - radius * radius;

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant > 0) {
            double root = (-b - sqrt(discriminant)) / (2.0 * a);
            if (root < tMin || root > tMax) {
                root = (-b + sqrt(discriminant)) / (2.0 * a);
                if (root < tMin || root > tMax) {
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
            rec.matPtr = matPtr;

            return true;
        }

        return false;
    }

    bool Cylinder::boundingBox(double time0, double time1, AxisAlignedBoundBox &outputBox) {
        outputBox = AxisAlignedBoundBox(
                position - Vector3D(radius, y0, radius),
                position + Vector3D(radius, y1, radius)
        );
        return true;
    }

    extern "C" {
        RayTracer::IPrimitive *entryPoint(Point3D &center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &matPtr)
        {
            return new Cylinder(variables[0], variables[1], variables[2], center, matPtr);
        }

        char *getType()
        {
            return (char *)"primitive_cylinder";
        }
    }
}

