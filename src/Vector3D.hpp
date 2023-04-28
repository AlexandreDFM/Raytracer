/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

namespace Math {
    class Vector3D {
        public:
            Vector3D();
            Vector3D(const Vector3D &other);
            Vector3D (const Vector3D &&other);
            Vector3D(double x, double y, double z);
            ~Vector3D();
            double length();
            Vector3D operator +  (const Vector3D &other);
            Vector3D operator += (const Vector3D &other);
            Vector3D operator -  (const Vector3D &other);
            Vector3D operator -= (const Vector3D &other);
            Vector3D operator *  (const Vector3D &other);
            Vector3D operator *= (const Vector3D &other);
            Vector3D operator /  (const Vector3D &other);
            Vector3D operator /= (const Vector3D &other);
            Vector3D operator *  (const double &other);
            Vector3D operator *= (const double &other);
            Vector3D operator /  (const double &other);
            Vector3D operator /= (const double &other);
            Vector3D operator =  (const Vector3D &other);
            double dot(const Vector3D &other);

        double x;
        double y;
        double z;
        protected:
        private:
    };
} // namespace Math

#endif /* !VECTOR3D_HPP_ */
