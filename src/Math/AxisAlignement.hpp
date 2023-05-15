/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AxisAlignement.hpp
*/

#ifndef AXISALIGNEMENT_HPP_
	#define AXISALIGNEMENT_HPP_

    #include "Ray.hpp"
    #include "Math.hpp"

class AxisAlignedBoundBox {
    public:
        AxisAlignedBoundBox() = default;
        AxisAlignedBoundBox(const Point3D& a, const Point3D& b)
        {
            minimum = a;
            maximum = b;
        }

        [[nodiscard]] Point3D min() const
        {
            return minimum;
        }
        [[nodiscard]] Point3D max() const
        {
            return maximum;
        }

        [[nodiscard]] bool hit(const RayTracer::Ray& r, double tMin, double tMax) const {
            for (int a = 0; a < 3; a++) {
                auto t0 = fmin((minimum[a] - r.origin()[a]) / r.direction()[a],
                               (maximum[a] - r.origin()[a]) / r.direction()[a]);
                auto t1 = fmax((minimum[a] - r.origin()[a]) / r.direction()[a],
                               (maximum[a] - r.origin()[a]) / r.direction()[a]);
                tMin = fmax(t0, tMin);
                tMax = fmin(t1, tMax);
                if (tMax <= tMin)
                    return false;
            }
            return true;
        }

    public :
        Point3D minimum;
        Point3D maximum;
};

#endif /*AXISALIGNEMENT_HPP_*/
