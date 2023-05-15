/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera(int width, int height, Point3D &lookFrom, Point3D &lookAt, Vector3D &vectorUp, double fov, double aspectRatio)
    {
        auto theta = Math::degrees_to_radians(fov);
        auto h = tan(theta / 2);
        auto viewportHeight = 2.0 * h;
        auto viewportWidth = aspectRatio * viewportHeight;

        Vector3D vectorW = lookFrom - lookAt;
        auto w = Vector3D::unitVector(vectorW);
        Vector3D vectorU = Vector3D::cross(vectorUp, w);
        auto u = Vector3D::unitVector(vectorU);
        auto v = Vector3D::cross(w, u);

        this->_width = width;
        this->_height = height;
        this->_origin = lookFrom;
        this->_horizontal = u * viewportWidth;
        this->_vertical = v * viewportHeight;
        this->_lower_left_corner = this->_origin - this->_horizontal / 2 - this->_vertical / 2 - w;
    }

    Ray Camera::getRay(double u, double v) const {
        return {this->_origin, this->_lower_left_corner + this->_horizontal * u + this->_vertical * v - this->_origin};
    }

    void Camera::getResolution(int &width, int &height) const
    {
        width = this->_width;
        height = this->_height;
    }
}
