/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace RayTracer {
    Core::Core(const std::string &configPath, const std::string &libPath) {
        this->_configHelper = new LibConfig(configPath);
        auto cameraResolutionWidth = this->_configHelper->get<int>("camera.resolution.width");
        auto cameraResolutionwHeight = this->_configHelper->get<int>("camera.resolution.height");
        auto cameraFov = this->_configHelper->get<float>("camera.fieldOfView");
        // auto cameraPosX = this->_configHelper->get<float>("camera.position.x");
        // auto cameraPosY = this->_configHelper->get<float>("camera.position.y");
        // auto cameraPosZ = this->_configHelper->get<float>("camera.position.z");
        // auto cameraRotX = this->_configHelper->get<float>("camera.rotation.x");
        // auto cameraRotY = this->_configHelper->get<float>("camera.rotation.y");
        // auto cameraRotZ = this->_configHelper->get<float>("camera.rotation.z");
        // Math::Point3D cameraPosition = Math::Point3D(cameraPosX, cameraPosY, cameraPosZ);
        // Vector3D cameraRotation = Math::Vector3D(cameraRotX, cameraRotY, cameraRotZ);
        this->_camera = std::make_unique<Camera>();
        this->_camera->setResolution(cameraResolutionWidth, cameraResolutionwHeight);
        this->_camera->setFov(cameraFov);
        // this->_camera->setRotation(cameraRotation);
        // this->_camera->origin = cameraPosition;

        // Créer les objets

        std::shared_ptr<IMaterial> material = std::make_shared<Lambertian>(color(0.8, 0.8, 0.0));

        for (int i = 0, length = this->_configHelper->getLength("primitives.spheres"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "z", i);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "r", i);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.spheres", "material", i);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.r", i);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.g", i);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.b", i);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "fuzz", i);
            auto materialComponent = RayTracer::Factory::createMaterial(materialType, point3 (colorR, colorG, colorB), fuzz);
            this->_world.add(RayTracer::Factory::createPrimitive("sphere", point3(x, y, z), r, materialComponent));
        }

        // Créer les lumières
    }

    color Core::RayColor(const RayTracer::Ray& r, const RayTracer::IShape& world, int depth)
    {
        hit_record rec;
        // If we've exceeded the ray bounce limit, no more light is gathered.
        if (depth <= 0)
            return color(0,0,0);
        if (world.hit(r, 0.001, Math::infinity, rec)) {
            RayTracer::Ray scattered;
            color attenuation;
            if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
                return attenuation * RayColor(scattered, world, depth-1);
            return color(0,0,0);
        }
        Vector3D unit_direction = unit_vector(r.direction());
        auto t = 0.5*(unit_direction.y() + 1.0);
        return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
    }


    void Core::run() {
        int width, height;
        const int max_depth = 50;
        const int samples_per_pixel = 100;
        this->_camera->getResolution(width, height);
        std::cout << "P3\n" << width << ' ' << height << "\n255\n";
        for (int j = height - 1; j >= 0; --j) {
            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            for (int i = 0; i < width; ++i) {
                color pixel_color(0, 0, 0);
                for (int s = 0; s < samples_per_pixel; ++s) {
                    auto u = (i + Math::random_double()) / (width - 1);
                    auto v = (j + Math::random_double()) / (height - 1);
                    RayTracer::Ray r = this->_camera->getRay(u, v);
                    pixel_color += RayColor(r, this->_world, max_depth);
                }
                Color::write_color(std::cout, pixel_color, samples_per_pixel);
            }
        }
        std::cerr << "\nDone.\n";
    }
}
