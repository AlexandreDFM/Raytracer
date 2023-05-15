/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ambient.cpp
*/

#include "Ambient.hpp"

namespace RayTracer {
    Ambient::Ambient(Vector3D &position, Vector3D &direction, Color3D &color)
            : _position(position), _direction(direction), _color(color)
    {}

    Vector3D Ambient::getPosition() const {
        return _position;
    }

    Vector3D Ambient::getDirection(const Point3D &point) const {
        return {0, 0, 0};
    }

    Color3D Ambient::getColor() const {
        return _color;
    }
}

extern "C" {
    RayTracer::Ambient *entryPoint(Vector3D position, Vector3D direction, Color3D color) {
        return new RayTracer::Ambient(position, direction, color);
    }

    char *getType() {
        return (char *)"light_ambient";
    }
}
