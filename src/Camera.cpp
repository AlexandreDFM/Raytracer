/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera() {
        auto aspect_ratio = 16.0 / 9.0;
        auto viewport_height = 2.0;
        auto viewport_width = aspect_ratio * viewport_height;
        auto focal_length = 1.0;

        origin = point3(0, 0, 0);
        horizontal = Vector3D(viewport_width, 0.0, 0.0);
        vertical = Vector3D(0.0, viewport_height, 0.0);
        lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vector3D(0, 0, focal_length);
    }

    Ray Camera::getRay(double u, double v) const {
        return Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
    }

    void Camera::setResolution(int width, int height)
    {
        this->horizontal = Vector3D(width, 0.0, 0.0);
        this->vertical = Vector3D(0.0, height, 0.0);
    }

    void Camera::setFov(float fov)
    {
        this->lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vector3D(0, 0, fov);
    }

    void Camera::getResolution(int &width, int &height) const
    {
        width = this->horizontal.x();
        height = this->vertical.y();
    }
}
