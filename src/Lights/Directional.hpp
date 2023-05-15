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
        Directional(const Vector3D& position, const Vector3D& direction, const Color3D &color);
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
    RayTracer::Directional *entryPoint(Vector3D position, Vector3D direction, Color3D color);
    char *getType();
}

#endif /*DIRECTIONAL_HPP_*/

