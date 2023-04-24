/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** main
*/

#include "src/Vector3D.hpp"
#include "src/Point3D.hpp"
#include "src/Camera.hpp"
#include "src/Sphere.hpp"
#include "src/Ray.hpp"
#include "src/Rectangle3D.hpp"

int main ()
{
    RayTracer::Camera cam;
    RayTracer::Sphere s(RayTracer::Point3D(0,0,-1),0.5);
    for (/* go through the Y axis */) {
        for (/* go through the X axis */) {
            double u = /* get a certain amount of X */;
            double v = /* get a certain amount of Y */;
            RayTracer::Ray r = cam.ray(u , v );
            if (s.hits(r)) {
            // something
            } else {
            // something else
            }
        }
    }
}
