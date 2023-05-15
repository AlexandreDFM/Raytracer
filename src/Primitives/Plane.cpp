/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer {
    Plane::Plane(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> &mat)
    {
        x0 = _x0;
        x1 = _x1;
        z0 = _z0;
        z1 = _z1;
        k = _k;
        mp = mat;
    }

    bool Plane::hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const
    {
        auto t = (k - r.origin().y()) / r.direction().y();
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

    extern "C" {
        RayTracer::IPrimitive *entryPoint(std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &matPtr)
        {
            return new RayTracer::Plane(variables[0], variables[1], variables[2], variables[3], variables[4], matPtr);
        }

        char *getType()
        {
            return (char *)"primitive_plane";
        }
    }
}

