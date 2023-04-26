/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** AShape.hpp
*/

#ifndef ASHAPE
	#define ASHAPE

class AShape {
	public:
		~AShape() = default;
        virtual bool hits(Ray ray) = 0;
	protected:
        Math::Point3D origin;
        double radius;
};

#endif /*ASHAPE*/
