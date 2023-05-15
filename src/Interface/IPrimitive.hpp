/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** IPrimitive.hpp
*/

#ifndef ISHAPE
	#define ISHAPE

     #include "Ray.hpp"
     #include "Struct.hpp"
     #include "Vector3D.hpp"
     #include "Math/AxisAlignement.hpp"

namespace RayTracer {
    class IMaterial;

    struct hitRecord {
        Point3D p;
        double t;
        double u;
        double v;
        bool front_face;
        Vector3D normal;
        std::shared_ptr<RayTracer::IMaterial> matPtr;
        inline void set_face_normal(const RayTracer::Ray& r, const Vector3D& outward_normal)
        {
            front_face = Vector3D::dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal :-outward_normal;
        }
    };

    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;
            virtual bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const = 0;
            virtual bool boundingBox(double time0, double time1, AxisAlignedBoundBox& outputBox) const = 0;
    };
}

#endif /*ISHAPE*/
