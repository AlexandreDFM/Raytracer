/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Directional.cpp
*/

#include "Directional.hpp"

namespace RayTracer {
    Directional::Directional(const Vector3D& position, const Vector3D& direction, const color &color)
            : _position(position), _direction(direction), _color(color)
    {}

    Vector3D Directional::getPosition() const {
        return _position;
    }

    Vector3D Directional::getDirection(const point3 &point) const {
        return -_direction;
    }

    color Directional::getColor() const {
        return _color;
    }
}

extern "C" {
    RayTracer::Directional *entryPoint(Vector3D position, Vector3D direction, color color) {
        return new RayTracer::Directional(position, direction, color);
    }

    char *getType() {
        return (char *)"light_directional";
    }
}
