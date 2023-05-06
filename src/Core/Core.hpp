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
    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Rectangle3D.hpp"
    #include "../Wrapper/Wrapper.hpp"
    #include "../Factory/Factory.hpp"
    #include "../Config/LibConfig.hpp"

namespace RayTracer {
    class Core {
    public:
        Core(const std::string &configPath, const std::string &libPath);
        ~Core() = default;
        void run();
    private:
        LibConfig *_configHelper;
        std::vector<IShape *> _shapes;
        std::unique_ptr<Camera> _camera;
    };
}

#endif /*CORE_HPP_*/
