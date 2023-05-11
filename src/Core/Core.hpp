 /*
 ** EPITECH PROJECT, 2023
 ** arcade
 ** File description:
 ** Core.hpp
 */

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include "IShape.hpp"
    #include "Camera.hpp"
    #include "Color.hpp"
    #include "HittableList.hpp"
    #include "Factory/NewFactory.hpp"
    #include "Config/LibConfig.hpp"
    #include "Vector3D.hpp"
    #include "IMaterial.hpp"

namespace RayTracer {
    class Core {
        public:
            Core(const std::string &configPath, const std::string &libPath);
            color RayColor(const RayTracer::Ray& r, const RayTracer::IShape& world, int depth);
            ~Core() = default;
            void run();
        private:
            NewFactory *_factory;
            LibConfig *_configHelper;
            std::vector<IShape *> _shapes;
            RayTracer::HittableList _world;
            std::unique_ptr<Camera> _camera;
    };
}

#endif /*CORE_HPP_*/
