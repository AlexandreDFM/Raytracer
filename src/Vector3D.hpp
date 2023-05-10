/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Vector3D
*/

#ifndef Vector3D_H
    #define Vector3D_H

    #include "rtweekend.hpp"
    #include <cmath>
    #include <iostream>

class Vector3D {
    public:
        Vector3D() : e{0,0,0} {}
        Vector3D(double x, double y, double z) : e{x, y, z} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        Vector3D operator-() const { return Vector3D(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        Vector3D& operator+=(const Vector3D &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        Vector3D& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        Vector3D& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        inline static Vector3D random() {
            return Vector3D(random_double(), random_double(), random_double());
        }

        inline static Vector3D random(double min, double max) {
            return Vector3D(random_double(min,max), random_double(min,max), random_double(min,max));
        }

        bool near_zero() const {
        // Return true if the vector is close to zero in all dimensions.
        const auto s = 1e-8;
        return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
    }
    public:
        double e[3];
};

// Type aliases for Vector3D
using point3 = Vector3D;   // 3D point
using color = Vector3D;    // RGB color

// Vector3D Utility Functions

inline std::ostream& operator<<(std::ostream &out, const Vector3D &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vector3D operator+(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vector3D operator-(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vector3D operator*(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vector3D operator*(double t, const Vector3D &v) {
    return Vector3D(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vector3D operator*(const Vector3D &v, double t) {
    return t * v;
}

inline Vector3D operator/(Vector3D v, double t) {
    return (1/t) * v;
}

inline double dot(const Vector3D &u, const Vector3D &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline Vector3D cross(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vector3D unit_vector(Vector3D v) {
    return v / v.length();
}

inline Vector3D random_in_unit_sphere() {
        while (true) {
        auto p = Vector3D::random(-1,1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

Vector3D random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

Vector3D reflect(const Vector3D& v, const Vector3D& n) {
    return v - 2*dot(v,n)*n;
}
#endif