/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point.cpp
*/

#include "Point.hpp"

namespace RayTracer {
    Point::Point(Vector3D position, Vector3D direction, color color)
            : _position(position), _direction(direction), _color(color)
    {}

    Vector3D Point::getPosition() const {
        return _position;
    }

    Vector3D Point::getDirection(const point3 &point) const {
        return -_direction;
    }

    color Point::getColor() const {
        return _color;
    }
}

extern "C" {
    RayTracer::Point *entryPoint(Vector3D position, Vector3D direction, color color) {
        return new RayTracer::Point(position, direction, color);
    }

    char *getType() {
        return (char *)"light_point";
    }
}

