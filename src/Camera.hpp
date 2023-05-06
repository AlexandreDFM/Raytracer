/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Rectangle3D.hpp"

namespace RayTracer {
    class Camera {
        public:
            Camera();
            ~Camera() = default;
            Ray ray(double u, double v);

            Math::Point3D origin;
            Rectangle3D screen;
        protected:
        private:
    };
}

#endif /* !CAMERA_HPP_ */
