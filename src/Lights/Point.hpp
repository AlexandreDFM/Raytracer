/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point.hpp
*/
#ifndef POINT_HPP_
	#define POINT_HPP_

    #include "ILight.hpp"

namespace RayTracer {
    class Point : public ILight {
    public:
        Point(Vector3D position, Vector3D direction, color color);

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
    RayTracer::Point *entryPoint(Vector3D position, Vector3D direction, color color);
    char *getType();
}

#endif /*POINT_HPP_*/
