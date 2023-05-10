#ifndef HITTABLE_H
    #define HITTABLE_H

    #include "Ray.hpp"

    #include "Math/Math.hpp"

class material;
//
//struct hit_record {
//point3 p;
//Vector3D normal;
//    double t;
//    bool front_face;
//    shared_ptr<material> mat_ptr;
//    inline void set_face_normal(const RayTracer::ray& r, const Vector3D& outward_normal) {
//        front_face = dot(r.direction(), outward_normal) < 0;
//        normal = front_face ? outward_normal :-outward_normal;
//    }
//};
//
//class hittable {
//public:
//    virtual bool hit(const RayTracer::ray& r, double t_min, double t_max, hit_record& rec) const = 0;
//};

#endif
