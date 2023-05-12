/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point.cpp
*/

#include "Point.hpp"

namespace RayTracer {
    Point::Point(Vector3D position, Vector3D direction, double intensity) {
        _position = position;
        _direction = direction;
        _intensity = intensity;
    }

    Vector3D Point::getPosition() const {
        return _position;
    }

    Vector3D Point::getDirection(const point3 &point) const {
        return -_direction;
    }

    double Point::getIntensity(const point3 &point) const {
        return _intensity;
    }
}

extern "C" {
    RayTracer::Point *entryPoint(Vector3D position, Vector3D direction, double intensity) {
        return new RayTracer::Point(position, direction, intensity);
    }

    char *getType() {
        return (char *)"light_point";
    }
}

