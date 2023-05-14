/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera(int width, int height, point3 lookFrom, point3 lookAt, Vector3D vectorUp, double fov, double aspect_ratio)
    {
        auto theta = Math::degrees_to_radians(fov);
        auto h = tan(theta / 2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;

        auto w = Vector3D::unitVector(lookFrom - lookAt);
        auto u = Vector3D::unitVector(Vector3D::cross(vectorUp, w));
        auto v = Vector3D::cross(w, u);

        this->_width = width;
        this->_height = height;
        this->_origin = lookFrom;
        this->_horizontal = viewport_width * u;
        this->_vertical = viewport_height * v;
        this->_lower_left_corner = this->_origin - this->_horizontal/2 - this->_vertical / 2 - w;
    }

    Ray Camera::getRay(double u, double v) const {
        return {this->_origin, this->_lower_left_corner + u * this->_horizontal + v * this->_vertical - this->_origin};
    }

    void Camera::getResolution(int &width, int &height) const
    {
        width = this->_width;
        height = this->_height;
    }
}
