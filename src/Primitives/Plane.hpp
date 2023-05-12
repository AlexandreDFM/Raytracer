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

namespace RayTracer {
    class Plane : public IPrimitive {
        public:
            Plane(point3 pos, double radius, std::shared_ptr<IMaterial> m);
            bool hit(const RayTracer::Ray &r, double t_min, double t_max, hit_record &rec) const override;

        public:
            point3 center;
            std::shared_ptr<IMaterial> mat_ptr;
    };

//    bool intersectDisk(const Vec3f &n, const Vec3f &p0, const float &radius, const Vec3f &l0, const Vec3 &l)
//    {
//        float t = 0;
//        if (intersectPlane(n, p0, l0, l, t)) {
//            Vec3f p = l0 + l * t;
//            Vec3f v = p - p0;
//            float d2 = dot(v, v);
//            return (sqrtf(d2) <= radius);
//            // or you can use the following optimization (and precompute radius^2)
//            // return d2 <= radius2; // where radius2 = radius * radius
//        }
//
//        return false;
//    }

//    bool intersectPlane(const Vec3f &n, const Vec3f &p0, const Vec3f &l0, const Vec3f &l, float &t)
//    {
//        // assuming vectors are all normalized
//        float denom = dotProduct(n, l);
//        if (denom > 1e-6) {
//            Vec3f p0l0 = p0 - l0;
//            t = dotProduct(p0l0, n) / denom;
//            return (t >= 0);
//        }
//
//        return false;
//    }

    inline bool Plane::hit(const RayTracer::Ray &r, double t_min, double t_max, RayTracer::hit_record &rec) const
    {
        double denom = dot(r.direction(), center);
        if (denom > 1e-6) {
            point3 p = center - r.origin();
            double t = dot(p, center) / denom;
            if (t >= 0) {
                rec.t = t;
                rec.p = r.at(rec.t);
                rec.normal = center;
                rec.mat_ptr = mat_ptr;
                return true;
            }
        }
        return false;
    }

    extern "C" {
        IPrimitive *entryPoint(point3 center, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial> mat_ptr);
        char *getType();
    }
}
#endif /*PLANE_HPP_*/
