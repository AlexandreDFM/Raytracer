/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** AShape.hpp
*/

#ifndef ASHAPE
	#define ASHAPE

    #include "IShape.hpp"

 namespace RayTracer {
     class AShape : public IShape {
         public:
             AShape() = default;
             bool hit(const RayTracer::Ray& r, double t_min, double t_max, hit_record& rec) const override = 0;
     };
 }

#endif /*ASHAPE*/
