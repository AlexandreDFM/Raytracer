/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            //////////////////////// Constructors ////////////////////////
            Ray() = default;
            Ray(Math::Point3D origin, Math::Vector3D direction);
            Ray(const Ray &other);
            Ray(const Ray &&other);

            //////////////////////// Destructors ////////////////////////
            ~Ray() = default;

            //////////////////////// Operators ////////////////////////
            Ray operator+(const Ray &other);
            Ray operator+=(const Ray &other);
            Ray operator-(const Ray &other);

            //////////////////////// Attributes ////////////////////////
            Math::Point3D origin;
            Math::Vector3D direction;
    };

}

#endif /* !RAY_HPP_ */
