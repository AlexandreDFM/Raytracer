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
            this->_haveGraphicalLib = true;
            this->loadDisplayModule();
        } else {
            this->_haveGraphicalLib = false;
        }

        this->createCamera();
        this->createObjects();
        this->createLights();

        this->_isRunning = true;
        this->_isRestarting = false;
    }

    void Core::restart()
    {
        this->_world.clear();
        this->_threads.clear();
        this->_camera.reset();
        this->_displayModule.reset();
        this->_isRestarting = false;
        if (this->_configHelper->isSet("graphical")) {
            this->_haveGraphicalLib = true;
            this->loadDisplayModule();
        } else {
            this->_haveGraphicalLib = false;
        }

        this->createCamera();
        this->createObjects();
        this->createLights();

        this->_isRunning = true;
        this->_isRestarting = false;
    }

    void Core::createCamera()
    {
        auto cameraResolutionWidth = this->_configHelper->get<int>("camera.resolution.width", 0);
        auto cameraResolutionHeight = this->_configHelper->get<int>("camera.resolution.height", 0);
        auto cameraFov = this->_configHelper->get<double>("camera.fieldOfView", 0);
        float aspectRatio = (float) cameraResolutionWidth / (float) cameraResolutionHeight;
        auto cameraPosX = this->_configHelper->get<double>("camera.position.x", 0);
        auto cameraPosY = this->_configHelper->get<double>("camera.position.y", 0);
        auto cameraPosZ = this->_configHelper->get<double>("camera.position.z", 0);
        auto cameraRotX = this->_configHelper->get<double>("camera.rotation.x", 0);
        auto cameraRotY = this->_configHelper->get<double>("camera.rotation.y", 0);
        auto cameraRotZ = this->_configHelper->get<double>("camera.rotation.z", 0);
        auto cameraVUpX = this->_configHelper->get<double>("camera.vectorUp.x", 0);
        auto cameraVUpY = this->_configHelper->get<double>("camera.vectorUp.y", 0);
        auto cameraVUpZ = this->_configHelper->get<double>("camera.vectorUp.z", 0);
        Point3D cameraPosition = Point3D(cameraPosX, cameraPosY, cameraPosZ);
        Point3D cameraRotation = Point3D(cameraRotX, cameraRotY, cameraRotZ);
        Vector3D cameraVectorUp = Vector3D(cameraVUpX, cameraVUpY, cameraVUpZ);
        this->_camera = std::make_unique<Camera>(cameraResolutionWidth, cameraResolutionHeight, cameraPosition, cameraRotation, cameraVectorUp, cameraFov, aspectRatio);
    }

    void Core::createObjects()
    {
        this->createSpheres();
        this->createPlanes();
        this->createRectangles();
        this->createCylinders();
        this->createCones();
    }

    void Core::createSpheres()
    {
        for (int i = 0, length = this->_configHelper->getLength("primitives.spheres"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "position.x", i, 0);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "position.y", i, 0);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "position.z", i, 0);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "r", i, 0);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.spheres", "material", i, "");
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "color.b", i, 0);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "fuzz", i, 0);
            if (this->_configHelper->isSetFromArray("primitives.spheres", "texture", i)) {
                auto texturePath = this->_configHelper->getLineValueFromArray<std::string>("primitives.spheres", "texture", i, "");
                auto value1 = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "value1", i, 0);
                auto value2 = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "value2", i, 0);
                auto value3 = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "value3", i, 0);
                auto value4 = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "value4", i, 0);
                auto value5 = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "value5", i, 0);
                auto value6 = this->_configHelper->getLineValueFromArray<double>("primitives.spheres", "value6", i, 0);
                std::vector<double> values = {value1, value2, value3, value4, value5, value6};
                std::shared_ptr<ITexture> texture = this->_factory->createTexture(texturePath, values);
                auto materialComponent = this->_factory->createTextureMaterial(materialType, texture, fuzz);
                this->_world.add(this->_factory->createPrimitive("sphere", Point3D(x, y, z), std::vector<double>({r}), materialComponent));
            } else {
                auto materialComponent = this->_factory->createMaterial(materialType, Color3D(colorR, colorG, colorB), fuzz);
               this->_world.add(this->_factory->createPrimitive("sphere", Point3D(x, y, z), std::vector<double>({r}), materialComponent));
            }
        }
    }

    void Core::createRectangles()
    {
        for (int i = 0, length = this->_configHelper->getLength("primitives.rectangles"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "position.x", i, 0);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "position.y", i, 0);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "position.z", i, 0);
            auto x0 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "x0", i, 0);
            auto x1 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "x1", i, 0);
            auto y0 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "y0", i, 0);
            auto y1 = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "y1", i, 0);
            auto k = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "k", i, 0);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "color.b", i, 0);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.rectangles", "fuzz", i, 0);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.rectangles", "material", i, "");
            auto materialComponent = this->_factory->createMaterial(materialType, Color3D(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("rectangle", Point3D(x, y, z), std::vector<double>({x0, x1, y0, y1, k}), materialComponent));
        }
    }

    void Core::createCylinders()
    {
        for (int i = 0, length = this->_configHelper->getLength("primitives.cylinders"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "position.x", i, 0);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "position.y", i, 0);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "position.z", i, 0);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "r", i, 0);
            auto h = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "h", i, 0);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.cylinders", "material", i, "");
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "color.b", i, 0);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.cylinders", "fuzz", i, 0);
            auto materialComponent = this->_factory->createMaterial(materialType, Color3D(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("cylinder", Point3D(x, y, z), std::vector<double>({r, h}), materialComponent));
        }
    }

    void Core::createCones()
    {
        for (int i = 0, length = this->_configHelper->getLength("primitives.cones"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "position.x", i, 0);
            auto y = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "position.y", i, 0);
            auto z = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "position.z", i, 0);
            auto r = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "r", i, 0);
            auto h = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "h", i, 0);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.cones", "material", i, "");
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "color.b", i, 0);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.cones", "fuzz", i, 0);
            auto materialComponent = this->_factory->createMaterial(materialType, Color3D(colorR, colorG, colorB), fuzz);
            this->_world.add(this->_factory->createPrimitive("cone", Point3D(x, y, z), std::vector<double>({r, h}), materialComponent));
        }
    }

    void Core::createPlanes()
    {
        for (int i = 0, length = this->_configHelper->getLength("primitives.planes"); i < length; i++) {
            auto normalX = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "normal.x", i, 0);
            auto normalY = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "normal.y", i, 0);
            auto normalZ = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "normal.z", i, 0);
            auto distance = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "distance", i, 0);
            auto materialType = this->_configHelper->getLineValueFromArray<std::string>("primitives.planes", "material", i, "");
            auto colorR = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "color.b", i, 0);
            auto fuzz = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "fuzz", i, 0);
            if (this->_configHelper->isSetFromArray("primitives.planes", "texture", i)) {
                auto texturePath = this->_configHelper->getLineValueFromArray<std::string>("primitives.planes", "texture", i, "");
                auto value1 = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "value1", i, 0);
                auto value2 = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "value2", i, 0);
                auto value3 = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "value3", i, 0);
                auto value4 = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "value4", i, 0);
                auto value5 = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "value5", i, 0);
                auto value6 = this->_configHelper->getLineValueFromArray<double>("primitives.planes", "value6", i, 0);
                std::vector<double> values = {value1, value2, value3, value4, value5, value6};
                std::shared_ptr<ITexture> texture = this->_factory->createTexture(texturePath, values);
                auto materialComponent = this->_factory->createTextureMaterial(materialType, texture, fuzz);
                this->_world.add(this->_factory->createPrimitive("plane", Point3D(normalX, normalY, normalZ), std::vector<double>({distance}), materialComponent));
            } else {
                auto materialComponent = this->_factory->createMaterial(materialType, Color3D(colorR, colorG, colorB), fuzz);
                this->_world.add(this->_factory->createPrimitive("plane", Point3D(normalX, normalY, normalZ), std::vector<double>({distance}), materialComponent));
            }
        }
    }

    void Core::createLights()
    {
        if (this->_configHelper->getLength("lights.ambient") > 0) {
            this->createAmbientLights();
        }
        if (this->_configHelper->getLength("lights.point") > 0) {
            this->createPointLights();
        }
        if (this->_configHelper->getLength("lights.directional") > 0) {
            this->createDirectionalLights();
        }
    }

    void Core::createAmbientLights()
    {
        if (this->_configHelper->isSet("lights.ambient.color.r")) {
            auto colorR = this->_configHelper->get<double>("lights.ambient.color.r", 0);
            auto colorG = this->_configHelper->get<double>("lights.ambient.color.g", 0);
            auto colorB = this->_configHelper->get<double>("lights.ambient.color.b", 0);
            this->_background = Color3D(colorR, colorG, colorB);
        } else {
            this->_background = Color3D(0, 0, 0);
        }
    }

    void Core::createPointLights()
    {
        for (int i = 0, length = this->_configHelper->getLength("lights.point"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("lights.point", "position.x", i, 0);
            auto y = this->_configHelper->getLineValueFromArray<double>("lights.point", "position.y", i, 0);
            auto z = this->_configHelper->getLineValueFromArray<double>("lights.point", "position.z", i, 0);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("lights.point", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("lights.point", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("lights.point", "color.b", i, 0);
            this->_world.add(this->_factory->createLight("point", Point3D(x, y, z), Point3D({0, 0, 0}), Color3D(colorR, colorG, colorB)));
        }
    }

    void Core::createDirectionalLights()
    {
        for (int i = 0, length = this->_configHelper->getLength("lights.directional"); i < length; i++) {
            auto x = this->_configHelper->getLineValueFromArray<double>("lights.directional", "position.x", i, 0);
            auto y = this->_configHelper->getLineValueFromArray<double>("lights.directional", "position.y", i, 0);
            auto z = this->_configHelper->getLineValueFromArray<double>("lights.directional", "position.z", i, 0);
            auto directionX = this->_configHelper->getLineValueFromArray<double>("lights.directional", "direction.x", i, 0);
            auto directionY = this->_configHelper->getLineValueFromArray<double>("lights.directional", "direction.y", i, 0);
            auto directionZ = this->_configHelper->getLineValueFromArray<double>("lights.directional", "direction.z", i, 0);
            auto colorR = this->_configHelper->getLineValueFromArray<double>("lights.directional", "color.r", i, 0);
            auto colorG = this->_configHelper->getLineValueFromArray<double>("lights.directional", "color.g", i, 0);
            auto colorB = this->_configHelper->getLineValueFromArray<double>("lights.directional", "color.b", i, 0);
            this->_world.add(this->_factory->createLight("directional", Point3D(x, y, z), Point3D(directionX, directionY, directionZ), Color3D(colorR, colorG, colorB)));
        }
    }

    void Core::loadDisplayModule()
    {
        auto cameraResolutionWidth = this->_configHelper->get<int>("camera.resolution.width", 0);
        auto cameraResolutionHeight = this->_configHelper->get<int>("camera.resolution.height", 0);
        auto graphicalName = this->_configHelper->get<std::string>("graphical.library", "");
        auto title = this->_configHelper->get<std::string>("graphical.title", "");
        auto width = this->_configHelper->get<int>("graphical.resolution.width", 0);
        auto height = this->_configHelper->get<int>("graphical.resolution.height", 0);
        auto fps = this->_configHelper->get<int>("graphical.fps", 0);
        this->_displayModule = this->_factory->createDisplay(graphicalName, width, height, cameraResolutionWidth, cameraResolutionHeight, fps, title);
    }

    Color3D Core::RayColor(const RayTracer::Ray& r, const Color3D &background, const RayTracer::IPrimitive& world, int depth)
    {
        hitRecord rec;
        // If we've exceeded the ray bounce limit, no more light is gathered.
        if (depth <= 0)
            return {0, 0, 0};
        if (!world.hit(r, 0.001, Math::infinity, rec))
            return background;
        RayTracer::Ray scattered = {Point3D(0, 0, 0), Point3D(0, 0, 0)};
        Color3D attenuation = {0, 0, 0};
        Color3D emitted = rec.matPtr->emitted(rec.u, rec.v, rec.p);
        if (!rec.matPtr->scatter(r, rec, attenuation, scattered))
            return emitted;
        return emitted + attenuation * RayColor(scattered, background, world, depth - 1);
    }

    void Core::render(int index, int start, int end, int width, int height, int samples_per_pixel, int max_depth)
    {
        for (int j = height - 1 - start; j > height - 1 - end && this->_isRunning; --j) {
            for (int i = 0; i < width && this->_isRunning; ++i) {
                Color3D pixelColor(0, 0, 0);
                for (int s = 0; s < samples_per_pixel && this->_isRunning; ++s) {
                    auto u = (i + Math::random_double()) / (width - 1);
                    auto v = (j + Math::random_double()) / (height - 1);
                    RayTracer::Ray r = this->_camera->getRay(u, v);
                    pixelColor += RayColor(r, this->_background, this->_world, max_depth);
                }
                this->_colors[index].push_back(pixelColor);
                if (this->_haveGraphicalLib) {
                    this->_displayModule->addPixel(i, height - j - 1, pixelColor.x(), pixelColor.y(), pixelColor.z(), samples_per_pixel);
                }
            }
        }
    }

    void Core::checkEvents(EventType type)
    {
        if (type == EventType::PAUSE) {
            this->_isPaused = !this->_isPaused;
        }
        if (type == EventType::CLOSE) {
            this->_isRunning = false;
        }
        if (type == EventType::RESTART) {
            this->_isPaused = false;
            this->_isRunning = false;
            this->_isRestarting = true;
        }
    }

    void Core::displayLoop()
    {
        while (this->_displayModule->isOpen() && !this->_isRestarting) {
            if (this->_isPaused) continue;
            this->_displayModule->display();
            Core::checkEvents(this->_displayModule->getEvent());
            this->_displayModule->update();
            this->_displayModule->clear();
        }
    }

    bool Core::run()
    {
        int width, height;
        const int max_depth = 50;
        const int samples_per_pixel = 100;
        this->_camera->getResolution(width, height);
        auto processor_count = std::thread::hardware_concurrency();
        if (processor_count == 0) processor_count = 2;

        if (this->_haveGraphicalLib) {
            this->_threads.push_back(std::thread(&Core::displayLoop, this));
            processor_count -= 1;
        }

        int work = height / (int) processor_count;
        int rest = height % (int) processor_count;
        int start = 0; int end = work;

        for (int index = 0; index < processor_count; index++) {
            if (rest > 0) {
                end++; rest--;
            }
            this->_colors.push_back(std::vector<Color3D>());
            this->_threads.push_back(std::thread(&Core::render, this, index, start, end, width, height, samples_per_pixel, max_depth));
            start = end; end += work;
        }
        for (auto &thread : this->_threads) thread.join();

        std::ofstream file("image.ppm");
        if (!file.is_open()) {
            std::cerr << "Error: cannot open file image.ppm\n";
            return false;
        }
        file << "P3\n" << width << ' ' << height << "\n255\n";
        for (auto &color : this->_colors) {
            for (auto &pixel : color) {
                Color::writeColor(file, pixel, samples_per_pixel);
            }
        }
        file.close();
        std::cerr << "\nDone.\n";
        if (this->_isRestarting) return true;
        return false;
    }
}
