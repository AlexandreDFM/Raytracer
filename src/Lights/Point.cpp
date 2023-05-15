/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point.cpp
*/

#include "Point.hpp"

namespace RayTracer {
    Point::Point(Vector3D position, Vector3D direction, Color3D color)
            : _position(position), _direction(direction), _color(color)
    {
    }

    Vector3D Point::getPosition() const {
        return _position;
    }

    Vector3D Point::getDirection(const Point3D &point) const {
        return -_direction;
    }

    Color3D Point::getColor() const {
        return _color;
    }
}

extern "C" {
    RayTracer::Point *entryPoint(Vector3D &position, Vector3D &direction, Color3D &color) {
        return new RayTracer::Point(position, direction, color);
    }

    char *getType() {
        return (char *)"light_point";
    }
}

