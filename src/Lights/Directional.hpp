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
        Directional(Vector3D position, Vector3D direction, double intensity);

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
    RayTracer::Directional *entryPoint(Vector3D position, Vector3D direction, double intensity);
    char *getType();
}

#endif /*DIRECTIONAL_HPP_*/

