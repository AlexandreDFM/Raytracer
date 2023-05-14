/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP_
	#define PLANE_HPP_

    #include "Ray.hpp"
    #include "IPrimitive.hpp"
    #include "../Math/AxisAlignement.hpp"

namespace RayTracer {
    class Plane : public IPrimitive {
        public:
            Plane(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<IMaterial> mat);

            virtual bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const override;

            virtual bool bounding_box(double time0, double time1, AxisAlignedBoundBox& output_box);

        public:
            std::shared_ptr<IMaterial> mp;
            double x0, x1, z0, z1, k;
    };
}

extern "C" {
    RayTracer::IPrimitive *entryPoint(std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr);
    char *getType();
}
#endif /*PLANE_HPP_*/
