/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ITexture.hpp
*/

#ifndef ITEXTURE
	#define ITEXTURE

    #include <vector>
    #include "Vector3D.hpp"

namespace RayTracer {
    class ITexture {
        public:
            virtual ~ITexture() = default;
            virtual Color3D value(double u, double v, const Point3D& p) const = 0;
    };
}

#endif /*ITEXTURE*/
