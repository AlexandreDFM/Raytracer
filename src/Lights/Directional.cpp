/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Directional.cpp
*/

#include "Directional.hpp"

namespace RayTracer {
    Directional::Directional(const Vector3D& position, const Vector3D& direction, const Color3D &color)
            : _position(position), _direction(direction), _color(color)
    {}

    Vector3D Directional::getPosition() const {
        return _position;
    }

    Vector3D Directional::getDirection(const Point3D &point) const {
        return -_direction;
    }

    Color3D Directional::getColor() const {
        return _color;
    }
}

extern "C" {
    RayTracer::Directional *entryPoint(Vector3D position, Vector3D direction, Color3D color) {
        return new RayTracer::Directional(position, direction, color);
    }

    char *getType() {
        return (char *)"light_directional";
    }
}
