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
    AxisAlignedBoundBox() {}
    AxisAlignedBoundBox(const point3& a, const point3& b) { minimum = a; maximum = b;}

    point3 min() const {return minimum; }
    point3 max() const {return maximum; }

    bool hit(const RayTracer::Ray& r, double t_min, double t_max) const {
        for (int a = 0; a < 3; a++) {
            auto t0 = fmin((minimum[a] - r.origin()[a]) / r.direction()[a],
                           (maximum[a] - r.origin()[a]) / r.direction()[a]);
            auto t1 = fmax((minimum[a] - r.origin()[a]) / r.direction()[a],
                           (maximum[a] - r.origin()[a]) / r.direction()[a]);
            t_min = fmax(t0, t_min);
            t_max = fmin(t1, t_max);
            if (t_max <= t_min)
                return false;
        }
        return true;
    }

    point3 minimum;
    point3 maximum;
};

#endif /*AXISALIGNEMENT_HPP_*/
