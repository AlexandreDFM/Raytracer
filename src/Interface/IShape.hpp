/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** IShape.hpp
*/

#ifndef ISHAPE
	#define ISHAPE

    #include <map>
    #include <vector>
    #include <memory>
    #include <string>
    #include <iostream>
    #include <functional>
    #include "../Ray.hpp"
    #include "../Point3D.hpp"
    #include "../Vector3D.hpp"

class IShape {
	public:
		~IShape() = default;
        virtual bool hits(RayTracer::Ray ray) = 0;
};

#endif /*ISHAPE*/
