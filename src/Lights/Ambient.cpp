/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ambient.cpp
*/

#include "Ambient.hpp"

namespace RayTracer {
    Ambient::Ambient(Vector3D position, Vector3D direction, color color)
            : _position(position), _direction(direction), _color(color)
    {}

    Vector3D Ambient::getPosition() const {
        return _position;
    }

    Vector3D Ambient::getDirection(const point3 &point) const {
        return Vector3D(0, 0, 0);
    }

    color Ambient::getColor() const {
        return _color;
    }
}

extern "C" {
    RayTracer::Ambient *entryPoint(Vector3D position, Vector3D direction, color color) {
        return new RayTracer::Ambient(position, direction, color);
    }

    char *getType() {
        return (char *)"light_ambient";
    }
}
