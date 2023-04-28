/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"

class Rectangle3D {
    public:
        Rectangle3D();
        Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
        ~Rectangle3D();
        Math::Point3D pointAt(double u, double v);

        Math::Point3D origin;
        Math::Vector3D bottom_side;
        Math::Vector3D left_side;
    protected:
    private:
};

#endif /* !RECTANGLE3D_HPP_ */
