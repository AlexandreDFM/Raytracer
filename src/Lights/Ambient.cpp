/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ambient.cpp
*/

#include "Ambient.hpp"

namespace RayTracer {
    Ambient::Ambient(Vector3D position, Vector3D direction, double intensity) {
        _position = position;
        _direction = direction;
        _intensity = intensity;
    }

    Vector3D Ambient::getPosition() const {
        return _position;
    }

    Vector3D Ambient::getDirection(const point3 &point) const {
        return Vector3D(0, 0, 0);
    }

    double Ambient::getIntensity(const point3 &point) const {
        return _intensity;
    }
}

extern "C" {
    RayTracer::Ambient *entryPoint(Vector3D position, Vector3D direction, double intensity) {
        return new RayTracer::Ambient(position, direction, intensity);
    }

    char *getType() {
        return (char *)"light_ambient";
    }
}
