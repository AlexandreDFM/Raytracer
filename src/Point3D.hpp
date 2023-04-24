/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "Vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Point3D &other);
            Point3D (const Point3D &&other);
            ~Point3D();
            Point3D operator+(const Vector3D &other);
            Point3D operator+=(const Vector3D &other);
            Point3D operator-(const Vector3D &other);

        double x;
        double y;
        double z;
        protected:
        private:
    };
}
#endif /* !POINT3D_HPP_ */
