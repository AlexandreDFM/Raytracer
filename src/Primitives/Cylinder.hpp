#ifndef CYLINDER_H
#define CYLINDER_H

#include "Ray.hpp"
#include "APrimitive.hpp"

namespace RayTracer {
    class Cylinder : public APrimitive {
    public:
        Cylinder(Point3D baseCenter, double height, double radius, std::shared_ptr<IMaterial>& m);
        bool hit(const RayTracer::Ray& r, double tMin, double tMax, hitRecord& rec) const override;

    private:
        Point3D baseCenter;
        double height;
        double radius;
        std::shared_ptr<IMaterial> matPtr;
    };

    extern "C" {
    IPrimitive* entryPoint(Point3D baseCenter, std::vector<double> variables, std::shared_ptr<RayTracer::IMaterial>& matPtr);
    char* getType();
    }
}

#endif /* CYLINDER_H */
