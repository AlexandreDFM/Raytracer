/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP_
	#define PLANE_HPP_

#include "Ray.hpp"
#include "APrimitive.hpp"
#include "../Math/AxisAlignement.hpp"

namespace RayTracer {
    class Plane : public APrimitive {
    public:
        Plane(const Vector3D& _normal, double _distance, std::shared_ptr<IMaterial>& _mat);
        bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;
        bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox);

    private:
        Vector3D normal;
        double distance;
        std::shared_ptr<IMaterial> mat;
    };

    extern "C" {
        RayTracer::IPrimitive *entryPoint(Vector3D &center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> matPtr);

        char *getType();
    }
}

#endif /*PLANE_HPP_*/
