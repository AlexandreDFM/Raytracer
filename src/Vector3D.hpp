/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

    #include <cmath>
    #include <string>
    #include <vector>
    #include <iostream>
    #include <algorithm>

namespace Math {
    class Vector3D {
        public:
            //////////////////////// Constructors ////////////////////////
            Vector3D();
            Vector3D(const Vector3D &other);
            Vector3D(const Vector3D &&other) noexcept;
            Vector3D(double x, double y, double z);

            //////////////////////// Destructors ////////////////////////
            ~Vector3D() = default;

            //////////////////////// Methods ////////////////////////
            double length();
            double dot(const Vector3D &other);

            //////////////////////// Operators ////////////////////////
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

            //////////////////////// Attributes ////////////////////////
            double x;
            double y;
            double z;
    };
}

#endif /* !VECTOR3D_HPP_ */
