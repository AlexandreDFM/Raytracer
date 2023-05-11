/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** IShape.hpp
*/

#ifndef ISHAPE
	#define ISHAPE

     #include "Ray.hpp"
     #include "Struct.hpp"
     #include "Vector3D.hpp"

class IMaterial;

struct hit_record {
    point3 p;
    Vector3D normal;
    double t;
    bool front_face;
    std::shared_ptr<IMaterial> mat_ptr;
    inline void set_face_normal(const RayTracer::Ray& r, const Vector3D& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};

namespace RayTracer {
    class IShape {
        public:
            virtual ~IShape() = default;
            virtual bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
    };
}

#endif /*ISHAPE*/
