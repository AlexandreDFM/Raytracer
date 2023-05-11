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
            Camera(int width, int height, point3 lookFrom, point3 lookAt, Vector3D vectorUp, double fov, double aspect_ratio);
            [[nodiscard]] Ray getRay(double u, double v) const;
            void getResolution(int &width, int &height) const;
        private:
            int _width;
            int _height;
            point3 _origin;
            point3 _lower_left_corner;
            Vector3D _horizontal;
            Vector3D _vertical;
    };
}

#endif

