/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core.hpp
*/
#ifndef CORE_HPP_
	#define CORE_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "../Wrapper/Wrapper.hpp"
#include "../Factory/Factory.hpp"
#include "../Interface/IShape.hpp"
#include "../Config/LibConfig.hpp"
#include "../Camera.hpp"
#include "../Point3D.hpp"
#include "../Vector3D.hpp"
#include "../Rectangle3D.hpp"

namespace RayTracer {
    class Core {
    public:
        Core(const std::string &configPath, const std::string &libPath);
        ~Core();
        void run();
    private:
        LibConfig *_configHelper;
        std::vector<IShape *> _shapes;
        std::unique_ptr<Camera> _camera;
    };
}

#endif /*CORE_HPP_*/
