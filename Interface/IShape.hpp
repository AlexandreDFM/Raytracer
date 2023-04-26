/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** IShape.hpp
*/

#ifndef ISHAPE
	#define ISHAPE

class IShape {
	public:
		~IShape() = default;
        virtual bool hits(Ray ray) = 0;
};

#endif /*ISHAPE*/
