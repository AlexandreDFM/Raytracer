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
            Camera(int width, int height, Point3D &lookFrom, Point3D &lookAt, Vector3D &vectorUp, double fov, double aspectRatio);
            [[nodiscard]] Ray getRay(double u, double v) const;
            void getResolution(int &width, int &height) const;
        private:
            int _width;
            int _height;
            Point3D _origin;
            Point3D _lower_left_corner;
            Vector3D _horizontal;
            Vector3D _vertical;
    };
}

#endif

