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
        Ambient(Vector3D position, Vector3D direction, color color);

        Vector3D getPosition() const override;

        Vector3D getDirection(const point3& point) const override;

        color getColor() const override;

    private:
        Vector3D _position;
        Vector3D _direction;
        color _color;
    };
}

extern "C" {
    RayTracer::Ambient *entryPoint(Vector3D position, Vector3D direction, color color);
    char *getType();
}


#endif /*AMBIENT_HPP_*/
