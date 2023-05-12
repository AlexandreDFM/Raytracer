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
        Point(Vector3D position, Vector3D direction, double intensity);

        Vector3D getPosition() const override;

        Vector3D getDirection(const point3& point) const override;

        double getIntensity(const point3& point) const override;

    private:
        Vector3D _position;
        Vector3D _direction;
        double _intensity;
    };
}

extern "C" {
    RayTracer::Point *entryPoint(Vector3D position, Vector3D direction, double intensity);
    char *getType();
}

#endif /*POINT_HPP_*/
