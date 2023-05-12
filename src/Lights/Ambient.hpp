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
        Ambient(Vector3D position, Vector3D direction, double intensity);

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
    RayTracer::Ambient *entryPoint(Vector3D position, Vector3D direction, double intensity);
    char *getType();
}


#endif /*AMBIENT_HPP_*/
