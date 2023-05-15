 /*
 ** EPITECH PROJECT, 2023
 ** arcade
 ** File description:
 ** Core.hpp
 */

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include <fstream>
    #include "Color.hpp"
    #include "Camera.hpp"
    #include "Vector3D.hpp"
    #include "IDisplay.hpp"
    #include "IMaterial.hpp"
    #include "IPrimitive.hpp"
    #include "HittableList.hpp"
    #include "Interface/IThread.hpp"
    #include "Factory/Factory.hpp"
    #include "Config/LibConfig.hpp"

namespace RayTracer {
    class Core {
        public:
            Core(const std::string &configPath, const std::string &libPath);
            Color3D RayColor(const RayTracer::Ray& r, const Color3D &background, const RayTracer::IPrimitive& world, int depth);
            ~Core() = default;
            void run();
            void checkEvents(EventType type);

            void createCamera();

            void createObjects();
            void createSpheres();
            void createPlanes();
            void createRectangles();
            void createCylinders();
            void createCones();

            void createLights();
            void createPointLights();
            void createAmbientLights();
            void createDirectionalLights();

            void displayLoop();
            void loadDisplayModule();
            void render(int index, int start, int end, int width, int height, int samples_per_pixel, int max_depth);
        private:
            bool _isPaused = false;
            bool _isRendering = false;
            Factory *_factory;
            bool haveGraphicalLib;
            Color3D _background;
            LibConfig *_configHelper;
            RayTracer::HittableList _world;
            std::unique_ptr<Camera> _camera;
            std::vector<std::thread> _threads;
            std::vector<IPrimitive *> _primitives;
            std::vector<std::vector<Color3D>> _colors;
            std::shared_ptr<IDisplay> _displayModule;
    };
}

#endif /*CORE_HPP_*/
