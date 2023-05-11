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
            Camera();
            [[nodiscard]] Ray getRay(double u, double v) const;
            void setResolution(int width, int height);
            void setFov(float fov);
            void getResolution(int &width, int &height) const;
        private:
            point3 origin;
            point3 lower_left_corner;
            Vector3D horizontal;
            Vector3D vertical;
    };
}

#endif

