/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ambient.hpp
*/

#ifndef AMBIENT_HPP_
	#define AMBIENT_HPP_

#include "ILight.hpp"

namespace RayTracer {
    class Ambient : public ILight {
    public:
        Ambient(Vector3D &position, Vector3D &direction, Color3D &color);
        [[nodiscard]] Vector3D getPosition() const override;
        [[nodiscard]] Vector3D getDirection(const Point3D& point) const override;
        [[nodiscard]] Color3D getColor() const override;

    private:
        Vector3D _position;
        Vector3D _direction;
        Color3D _color;
    };
}

extern "C" {
    RayTracer::Ambient *entryPoint(Vector3D position, Vector3D direction, Color3D color);
    char *getType();
}


#endif /*AMBIENT_HPP_*/
