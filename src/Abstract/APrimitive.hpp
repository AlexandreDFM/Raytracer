/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** APrimitive.hpp
*/

#ifndef ASHAPE
	#define ASHAPE

    #include "IPrimitive.hpp"

namespace RayTracer {
    class APrimitive : public IPrimitive {
        public:
            bool hit(const RayTracer::Ray& r, double t_min, double t_max, hitRecord& rec) const override;
            bool boundingBox(double time0, double time1, AxisAlignedBoundBox& output_box) const override;
    };
}

#endif /*ASHAPE*/
