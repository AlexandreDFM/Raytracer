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
    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace RayTracer {
    class IShape {
        public:
            virtual ~IShape() = default;
            virtual bool hits(Ray ray) = 0;
    };
}

#endif /*ISHAPE*/
