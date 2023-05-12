/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Directional.cpp
*/

#include "Directional.hpp"

namespace RayTracer {
    Directional::Directional(Vector3D position, Vector3D direction, double intensity) {
        _position = position;
        _direction = direction;
        _intensity = intensity;
    }

    Vector3D Directional::getPosition() const {
        return _position;
    }

    Vector3D Directional::getDirection(const point3 &point) const {
        return -_direction;
    }

    double Directional::getIntensity(const point3 &point) const {
        return _intensity;
    }
}

extern "C" {
    RayTracer::Directional *entryPoint(Vector3D position, Vector3D direction, double intensity) {
        return new RayTracer::Directional(position, direction, intensity);
    }

    char *getType() {
        return (char *)"light_directional";
    }
}
