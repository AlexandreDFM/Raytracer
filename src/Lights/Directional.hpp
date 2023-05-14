/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Directional.hpp
*/

#ifndef DIRECTIONAL_HPP_
	#define DIRECTIONAL_HPP_

    #include "ILight.hpp"

namespace RayTracer {
    class Directional : public ILight {
    public:
        Directional(const Vector3D& position, const Vector3D& direction, const color &color);

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
    RayTracer::Directional *entryPoint(Vector3D position, Vector3D direction, color color);
    char *getType();
}

#endif /*DIRECTIONAL_HPP_*/

