/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D
    #define RECTANGLE3D

    #include "Ray.hpp"
    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Primitives/Sphere.hpp"

class Rectangle3D {
    public:
        //////////////////////// Constructors ////////////////////////
        Rectangle3D() = default;
        Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
        //////////////////////// Destructors ////////////////////////
        ~Rectangle3D() = default;
        Math::Point3D pointAt(double u, double v);

        //////////////////////// Attributes ////////////////////////
        Math::Point3D origin;
        Math::Vector3D bottom_side;
        Math::Vector3D left_side;
};

#endif /* !RECTANGLE3D */
