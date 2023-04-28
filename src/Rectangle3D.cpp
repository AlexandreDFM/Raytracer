/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

Rectangle3D::Rectangle3D()
{
}

Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side) : origin(origin), bottom_side(bottom_side), left_side(left_side)
{
}

Rectangle3D::~Rectangle3D()
{
}

Math::Point3D Rectangle3D::pointAt(double u, double v)
{
    return Math::Point3D(this->origin.x + u * this->bottom_side.x + v * this->left_side.x,
                        this->origin.y + u * this->bottom_side.y + v * this->left_side.y,
                        this->origin.z + u * this->bottom_side.z + v * this->left_side.z);
}
