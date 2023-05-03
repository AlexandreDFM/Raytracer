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

namespace RayTracer {
    class Core {
    public:
        Core(const std::string &configPath);
        ~Core();
        void run();
    private:
        LibConfig *_configHelper;
        std::vector<IShape *> _shapes;
    };
}

#endif /*CORE_HPP_*/