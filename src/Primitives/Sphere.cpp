/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Sphere
*/

#include "Sphere.hpp"

#include <utility>


namespace RayTracer {
    Sphere::Sphere(Math::Point3D origin, double radius)
    {
        this->origin.x = origin.x;
        this->origin.y = origin.y;
        this->origin.z = origin.z;
        this->radius = radius;
    }

    Sphere::~Sphere()
    {
    }

    bool Sphere::hits(Ray ray)
    {
        // std::cout << this->radius << std::endl;
        double a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
        double b = 2 * (ray.direction.x * (ray.origin.x - this->origin.x) + ray.direction.y * (ray.origin.y - this->origin.y) + ray.direction.z * (ray.origin.z - this->origin.z));
        double c = (ray.origin.x - this->origin.x) * (ray.origin.x - this->origin.x) + (ray.origin.y - this->origin.y) * (ray.origin.y - this->origin.y) + (ray.origin.z - this->origin.z) * (ray.origin.z - this->origin.z) - this->radius * this->radius;
        double discriminant = b * b - 4 * a * c;
        // std::cout << "a: " << a << std::endl;
        // std::cout << "b: " << b << std::endl;
        // std::cout << "c: " << c << std::endl;
        // std::cout << "Discriminant: " << discriminant << std::endl;
        if (discriminant < 0)
            return false;
        return true;
        // double Radius = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
        // std::cout << "Radius: " << Radius << std::endl;
        // double b = 2 * (ray.direction.x * (ray.origin.x - this->origin.x) + ray.direction.y * (ray.origin.y - this->origin.y) + ray.direction.z * (ray.origin.z - this->origin.z));
        // std::cout << "b: " << b << std::endl;
        // double c = (ray.origin.x - this->origin.x) * (ray.origin.x - this->origin.x) + (ray.origin.y - this->origin.y) * (ray.origin.y - this->origin.y) + (ray.origin.z - this->origin.z) * (ray.origin.z - this->origin.z) - this->radius * this->radius;
        // std::cout << "c: " << c << std::endl;
        // double delta = b * b - 4 * Radius * c;
        // if (delta < 0) {
        //     return false;
        // }
        // else {
        //     std::cout << "Delta: " << delta << std::endl;
        //     return true;
        // }

    }
}

extern "C" RayTracer::Sphere *createObject(const Math::Point3D& origin, double radius)
{
    return new RayTracer::Sphere(origin, radius);
}

extern "C" char *getType()
{
    return (char *)"Sphere";
}
