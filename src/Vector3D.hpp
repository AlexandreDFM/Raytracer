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

        [[nodiscard]] double x() const ;
        [[nodiscard]] double y() const ;
        [[nodiscard]] double z() const ;

        Vector3D operator-() const ;
        double operator[](int i) const ;
        double &operator[](int i) ;
        Vector3D &operator+=(const Vector3D &v);
        Vector3D &operator/=(double t) ;
        Vector3D &operator*=(double t) ;

        [[nodiscard]] virtual double length() const;
        [[nodiscard]] virtual double lengthSquared() const;
        [[nodiscard]] virtual bool nearZero() const;

        friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);
        Vector3D operator+(const Vector3D &other) const;
        Vector3D operator-(const Vector3D &other) const;
        Vector3D operator*(const Vector3D &other) const;
        Vector3D operator*(double t) const;
        Vector3D operator/(double t) const;

        static Vector3D random();
        static Vector3D random(double min, double max);
        static double dot(const Vector3D &u, const Vector3D &v);
        static Vector3D cross(const Vector3D &u, const Vector3D &v);
        static Vector3D unitVector(Vector3D &v);
        static Vector3D randomInUnitSphere();
        static Vector3D randomUnitVector();
        static Vector3D reflect(const Vector3D &v, const Vector3D &n);
        static Vector3D refract(const Vector3D& uv, const Vector3D& n, double etaiOverEtat);

    public:
        double e[3];
};

typedef Vector3D Point3D;
typedef Vector3D Color3D;

#endif
