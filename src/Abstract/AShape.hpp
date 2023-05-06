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
            AShape();
            bool hits(Ray ray) override;
        protected:
            double radius;
            Math::Point3D origin;
    };
}

#endif /*ASHAPE*/
