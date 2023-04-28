/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Main.cpp
*/

#include "src/Vector3D.hpp"
#include "src/Point3D.hpp"
#include "src/Camera.hpp"
#include "src/Sphere.hpp"
#include "src/Ray.hpp"
#include "src/Rectangle3D.hpp"

int main()
{
    double width = 720;
    double height = 480;

    RayTracer::Camera cam;
    RayTracer::Sphere s(Math::Point3D(0,0, -1),0.5);
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            double u = double(j) / (width);
            double v = double(i) / (height);
            RayTracer::Ray r = cam.ray(u , v );
            if (s.hits(r)) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
