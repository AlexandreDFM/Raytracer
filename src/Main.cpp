/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Main.cpp
*/

#include "Camera.hpp"
#include "Core/Core.hpp"
#include "Exception/Usage/Usage.hpp"

int main(int argc, char **argv)
{
    Usage::CheckUsage(argc, argv);
    RayTracer::Core core("assets/Scene/Scene1", "lib/");

    double width = 720;
    double height = 480;

    RayTracer::Camera cam;
//    RayTracer::Sphere s(Math::Point3D(0,0, -1),0.5);
//    for (int i = 0; i < height - 1; i++) {
//        for (int j = 0; j < width; j++) {
//            double u = double(j) / (width);
//            double v = double(i) / (height);
//            RayTracer::Ray r = cam.ray(u , v );
//            if (s.hits(r)) {
//                std::cout << "X";
//            } else {
//                std::cout << " ";
//            }
//        }
//            std::cout << std::endl;
//    }
//    std::cout << std::endl;
}
