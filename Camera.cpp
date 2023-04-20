/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera()
    {
    }

    Camera::~Camera()
    {
    }

    Ray Camera::ray(double u, double v)
    {
        Math::Point3D origin = this->origin;
        Math::Point3D direction = this->screen.pointAt(u, v);
        Math::Vector3D directionVector = Math::Vector3D(direction.x - origin.x, direction.y - origin.y, direction.z - origin.z);
        return Ray(origin, directionVector);
    }
}
