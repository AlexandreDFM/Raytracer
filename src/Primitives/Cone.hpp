/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone.hpp
*/
#ifndef CONE_HPP_
	#define CONE_HPP_

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "APrimitive.hpp"
#include "Math/AxisAlignement.hpp"

namespace RayTracer {
    class Cone : public APrimitive {
    public:
        Cone(double _radius, double _height, const Vector3D& _position, std::shared_ptr<IMaterial> &_mat);
        bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;
        bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox);
    private:
        Vector3D position;
        double radius;
        double height;
        std::shared_ptr<IMaterial> matPtr;
    };

    extern "C" {
        IPrimitive *entryPoint(Point3D center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> &matPtr);

        char *getType();
    }
}


#endif /*CONE_HPP_*/
