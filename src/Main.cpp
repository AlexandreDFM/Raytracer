/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Main
*/

#include "Math/Math.hpp"
#include "Color.hpp"
#include "HittableList.hpp"
#include "./Primitives/Sphere.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "Interface/IShape.hpp"
#include <iostream>

color ray_color(const RayTracer::Ray& r, const RayTracer::IShape& world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    if (world.hit(r, 0.001, Math::infinity, rec)) {
        RayTracer::Ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return color(0,0,0);
    }

    Vector3D unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image

    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 480;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;
    const int max_depth = 50;

    // World

    RayTracer::HittableList world;

    auto material_ground = std::make_shared<Lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<Lambertian>(color(0.7, 0.3, 0.3));
    // auto material_left   = std::make_shared<metal>(color(0.8, 0.8, 0.8));
    // auto material_right  = std::make_shared<metal>(color(0.8, 0.6, 0.2));
    auto material_left   = std::make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);
    auto material_right  = std::make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

    world.add(std::make_shared<RayTracer::Sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(std::make_shared<RayTracer::Sphere>(point3(0.0, 0.0, -1.0), 0.5, material_center));
    world.add(std::make_shared<RayTracer::Sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(std::make_shared<RayTracer::Sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

    // Camera

    RayTracer::Camera cam;

    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + Math::random_double()) / (image_width-1);
                auto v = (j + Math::random_double()) / (image_height-1);
                RayTracer::Ray r = cam.getRay(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}
