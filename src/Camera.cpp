/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera() : origin(Math::Point3D(0, 0, 0)), screen(Math::Point3D(0, 0, 0), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 1, 0))
    {
    }

    Ray Camera::ray(double u, double v)
    {
        Math::Point3D direction = this->screen.pointAt(u, v);
        Math::Vector3D directionVector = Math::Vector3D(direction.x - this->origin.x, direction.y - this->origin.y, direction.z - this->origin.z);
        // std::cout << "Direction vector: " << directionVector.x << " " << directionVector.y << " " << directionVector.z << std::endl;
        return Ray(this->origin, directionVector);
    }
}
