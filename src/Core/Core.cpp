/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace RayTracer {
    Core::Core(const std::string &configPath, const std::string &libPath) {
        this->_factory = new Factory(libPath);
        this->_configHelper = new LibConfig(configPath);
        if (this->_configHelper->isSet("graphical")) {
            this->haveGraphicalLib = true;
            this->loadDisplayModule(libPath);
        } else {
            this->haveGraphicalLib = false;
        }
        // Créer la Caméra

        auto cameraResolutionWidth = this->_configHelper->get<int>("camera.resolution.width");
        auto cameraResolutionHeight = this->_configHelper->get<int>("camera.resolution.height");
        auto cameraFov = this->_configHelper->get<float>("camera.fieldOfView");
        float aspectRatio = (float) cameraResolutionWidth / (float) cameraResolutionHeight;
        auto cameraPosX = this->_configHelper->get<float>("camera.position.x");
        auto cameraPosY = this->_configHelper->get<float>("camera.position.y");
        auto cameraPosZ = this->_configHelper->get<float>("camera.position.z");
        auto cameraRotX = this->_configHelper->get<float>("camera.rotation.x");
        auto cameraRotY = this->_configHelper->get<float>("camera.rotation.y");
        auto cameraRotZ = this->_configHelper->get<float>("camera.rotation.z");
        auto cameraVUpX = this->_configHelper->get<float>("camera.vectorUp.x");
        auto cameraVUpY = this->_configHelper->get<float>("camera.vectorUp.y");
        auto cameraVUpZ = this->_configHelper->get<float>("camera.vectorUp.z");
        point3 cameraPosition = point3(cameraPosX, cameraPosY, cameraPosZ);
        point3 cameraRotation = point3(cameraRotX, cameraRotY, cameraRotZ);
        Vector3D cameraVectorUp = Vector3D(cameraVUpX, cameraVUpY, cameraVUpZ);
        this->_camera = std::make_unique<Camera>(cameraResolutionWidth, cameraResolutionHeight, cameraPosition, cameraRotation, cameraVectorUp, cameraFov, aspectRatio);

        // Créer les objets

        for (int i = 0, length = this->_configHelper->getLength("primitives.spheres"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "position.x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "position.y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "position.z", i);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "r", i);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.spheres", "material", i);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.r", i);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.g", i);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.b", i);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "fuzz", i);
            auto materialComponent = this->_factory->createMaterial(materialType, color(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("sphere", point3(x, y, z), std::vector<double>({r}), materialComponent));
        }

        for (int i = 0, length = this->_configHelper->getLength("primitives.rectangles"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "position.x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "position.y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "position.z", i);
            auto x0 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "x0", i);
            auto x1 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "x1", i);
            auto y0 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "y0", i);
            auto y1 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "y1", i);
            auto k = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "k", i);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "color.r", i);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "color.g", i);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "color.b", i);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "fuzz", i);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.rectangles", "material", i);
            auto materialComponent = this->_factory->createMaterial(materialType, color(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("rectangle", point3(x, y, z), std::vector<double>({x0, x1, y0, y1, k}), materialComponent));
        }

        for (int i = 0, length = this->_configHelper->getLength("primitives.cylinders"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "position.x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "position.y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "position.z", i);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "r", i);
            auto y0 = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "y0", i);
            auto y1 = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "y1", i);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.cylinders", "material", i);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "color.r", i);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "color.g", i);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "color.b", i);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "fuzz", i);
            auto materialComponent = this->_factory->createMaterial(materialType, color(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("cylinder", point3(x, y, z), std::vector<double>({r, y0, y1}), materialComponent));
        }

        for (int i = 0, length = this->_configHelper->getLength("primitives.cones"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "position.x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "position.y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "position.z", i);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "r", i);
            auto h = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "h", i);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.cones", "material", i);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "color.r", i);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "color.g", i);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "color.b", i);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "fuzz", i);
            auto materialComponent = this->_factory->createMaterial(materialType, color(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("cone", point3(x, y, z), std::vector<double>({r, h}), materialComponent));
        }

        // Créer les plans

        for (int i = 0, length = this->_configHelper->getLength("primitives.planes"); i < length; i++) {
            auto position = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "position", i);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.planes", "material", i);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "color.r", i);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "color.g", i);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "color.b", i);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "fuzz", i);
            auto materialComponent = this->_factory->createMaterial(materialType, color(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("plane", point3(0, position, 0), std::vector<double>({0}), materialComponent));
        }

        // Créer les lumières

        for (int i = 0, length = this->_configHelper->getLength("lights.point"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("lights.point", "x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("lights.point", "y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("lights.point", "z", i);
            auto intensity = this->_configHelper->getLineValueFromArray<double>("lights.point", "intensity", i);
            this->_world.add(this->_factory->createLight("point", point3(x, y, z), point3(0, 0, 0), intensity));
        }

        for (int i = 0, length = this->_configHelper->getLength("lights.directional"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("lights.directional", "x", i);
            auto y = this->_configHelper->getLineValueFromArray<double>("lights.directional", "y", i);
            auto z = this->_configHelper->getLineValueFromArray<double>("lights.directional", "z", i);
            auto directionX = this->_configHelper->getLineValueFromArray<double>("lights.directional", "direction.x", i);
            auto directionY = this->_configHelper->getLineValueFromArray<double>("lights.directional", "direction.y", i);
            auto directionZ = this->_configHelper->getLineValueFromArray<double>("lights.directional", "direction.z", i);
            auto intensity = this->_configHelper->getLineValueFromArray<double>("lights.directional", "intensity", i);
            this->_world.add(this->_factory->createLight("directional", point3(x, y, z), point3(directionX, directionY, directionZ), intensity));
        }
    }

    void Core::loadDisplayModule(const std::string &libPath)
    {
        auto cameraResolutionWidth = this->_configHelper->get<int>("camera.resolution.width");
        auto cameraResolutionHeight = this->_configHelper->get<int>("camera.resolution.height");
        auto graphicalName = this->_configHelper->get<std::string>("graphical.library");
        auto title = this->_configHelper->get<std::string>("graphical.title");
        auto width = this->_configHelper->get<int>("graphical.resolution.width");
        auto height = this->_configHelper->get<int>("graphical.resolution.height");
        auto fps = this->_configHelper->get<int>("graphical.fps");
        this->_displayModule = this->_factory->createDisplay(graphicalName, width, height, cameraResolutionWidth, cameraResolutionHeight, fps, title);
    }


    color Core::RayColor(const RayTracer::Ray& r, const RayTracer::IPrimitive& world, int depth)
    {
        hit_record rec;
        // If we've exceeded the ray bounce limit, no more light is gathered.
        if (depth <= 0)
            return {0,0,0};
        if (!world.hit(r, 0.001, Math::infinity, rec))
            return {0,0,0};
        RayTracer::Ray scattered;
        color attenuation;
        color emmited = rec.mat_ptr->emitted(rec.u, rec.v, rec.p);
        if (!rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return emmited;
        return emmited + attenuation * RayColor(scattered, world, depth-1);
    }


    void Core::run()
    {
        if (this->haveGraphicalLib) {
            this->graphicalRender();
        } else {
            this->standardRender();
        }
    }

    void Core::render(int index, int start, int end, int width, int height, int samples_per_pixel, int max_depth)
    {
        for (int j = start; j < end; j++) {
            for (int i = 0; i < width; i++) {
                color pixel_color(0, 0, 0);
                for (int s = 0; s < samples_per_pixel; ++s) {
                    auto u = (i + Math::random_double()) / (width - 1);
                    auto v = (j + Math::random_double()) / (height - 1);
                    RayTracer::Ray r = this->_camera->getRay(u, v);
                    pixel_color += RayColor(r, this->_world, max_depth);
                }
                this->_colors[index].push_back(pixel_color);
                if (this->haveGraphicalLib) {
                    this->_displayModule->addPixel(i, height - j - 1, pixel_color.x(), pixel_color.y(), pixel_color.z(), samples_per_pixel);
                }
            }
        }
    }

    void Core::standardRender()
    {
        int width, height;
        const int max_depth = 100;
        const int samples_per_pixel = 200;
        this->_camera->getResolution(width, height);
        std::cout << "P3\n" << width << ' ' << height << "\n255\n";
        auto processor_count = std::thread::hardware_concurrency();
        if (processor_count == 0) processor_count = 1;

        // Split the work
        int work = height / processor_count;
        int rest = height % processor_count;
        int start = 0;
        int end = work;
        for (int index = 0; index < processor_count; index++) {
            if (rest > 0) {
                end++;
                rest--;
            }
            this->_colors.push_back(std::vector<color>());
            this->_threads.push_back(std::thread(&Core::render, this, index, start, end, width, height, samples_per_pixel, max_depth));
            start = end;
            end += work;
        }

        for (auto &thread : this->_threads) thread.join();

        for (auto &color : this->_colors) {
            for (auto &pixel : color) {
                Color::writeColor(std::cout, pixel, samples_per_pixel);
            }
        }

//        for (auto color = this->_colors.rbegin(); color != this->_colors.rend(); color++) {
//            // Iterate over color vector from the end
//            for (auto pixel = color->rbegin(); pixel != color->rend(); pixel++) {
//                Color::writeColor(std::cout, *pixel, samples_per_pixel);
//            }
//        }
        std::cerr << "\nDone.\n";
    }

    void Core::checkEvents(EventType type)
    {
        if (type == EventType::PAUSE) {
            this->_isPaused = !this->_isPaused;
        }
    }

    void Core::graphicalLoop()
    {
        while (this->_displayModule->isOpen()) {
            if (this->_isPaused) continue;
            this->_displayModule->display();
            Core::checkEvents(this->_displayModule->getEvent());
            this->_displayModule->update();
            this->_displayModule->clear();
        }
    }

    void Core::graphicalRender()
    {
        int width, height;
        const int max_depth = 50;
        const int samples_per_pixel = 100;
        this->_camera->getResolution(width, height);
        std::cout << "P3\n" << width << ' ' << height << "\n255\n";
        auto processor_count = std::thread::hardware_concurrency();
        if (processor_count == 0) processor_count = 3;

        // Split the work

        this->_threads.push_back(std::thread(&Core::graphicalLoop, this));

         processor_count -= 1;

        int work = height / (int) processor_count;
        int rest = height % (int) processor_count;
        int start = 0; int end = work;

        for (int index = 0; index < processor_count; index++) {
            if (rest > 0) {
                end++; rest--;
            }
            this->_colors.push_back(std::vector<color>());
            this->_threads.push_back(std::thread(&Core::render, this, index, start, end, width, height, samples_per_pixel, max_depth));
            start = end; end += work;
        }

        for (auto &thread : this->_threads) thread.join();
        for (auto &color : this->_colors) {
            for (auto &pixel : color) Color::writeColor(std::cout, pixel, samples_per_pixel);
        }

        std::cerr << "\nDone.\n";
    }
}
