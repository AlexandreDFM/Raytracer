/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Vector3D
*/

#ifndef Vector3D_H
    #define Vector3D_H

    #include <iostream>
    #include "Math/Math.hpp"

class Vector3D {
    public:
        Vector3D();
        Vector3D(double x, double y, double z);

        [[nodiscard]] virtual double x() const;
        [[nodiscard]] virtual double y() const;
        [[nodiscard]] virtual double z() const;

        virtual Vector3D operator-() const;
        virtual double operator[](int i) const;
        virtual double &operator[](int i);
        virtual Vector3D &operator+=(const Vector3D &v);
        virtual Vector3D &operator/=(double t);
        virtual Vector3D &operator*=(double t);

        [[nodiscard]] virtual double length() const;
        [[nodiscard]] virtual double length_squared() const;
        [[nodiscard]] virtual bool near_zero() const;

        friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);
        friend Vector3D operator+(const Vector3D &u, const Vector3D &v);
        friend Vector3D operator-(const Vector3D &u, const Vector3D &v);
        friend Vector3D operator*(const Vector3D &u, const Vector3D &v);
        friend Vector3D operator*(double t, const Vector3D &v);
        friend Vector3D operator*(const Vector3D &v, double t);
        friend Vector3D operator/(Vector3D v, double t);

        static Vector3D random();
        static Vector3D random(double min, double max);
        static double dot(const Vector3D &u, const Vector3D &v);
        static Vector3D cross(const Vector3D &u, const Vector3D &v);
        static Vector3D unitVector(Vector3D v);
        static Vector3D randomInUnitSphere();
        static Vector3D randomUnitVector();
        static Vector3D reflect(const Vector3D &v, const Vector3D &n);
        static Vector3D refract(const Vector3D& uv, const Vector3D& n, double etaiOverEtat);

    public:
        double e[3];
};

using point3 = Vector3D;   // 3D point
using color = Vector3D;    // RGB color

#endif
