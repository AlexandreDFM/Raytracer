/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Ray.hpp"

namespace RayTracer {
    class Camera {
        public:
            Camera() {
                auto aspect_ratio = 16.0 / 9.0;
                auto viewport_height = 2.0;
                auto viewport_width = aspect_ratio * viewport_height;
                auto focal_length = 1.0;

                origin = point3(0, 0, 0);
                horizontal = Vector3D(viewport_width, 0.0, 0.0);
                vertical = Vector3D(0.0, viewport_height, 0.0);
                lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vector3D(0, 0, focal_length);
            }

            Ray getRay(double u, double v) const {
                return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            }

        private:
            point3 origin;
            point3 lower_left_corner;
            Vector3D horizontal;
            Vector3D vertical;
    };
}

#endif

