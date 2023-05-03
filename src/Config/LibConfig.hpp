/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** LibConfig.hpp
*/

#ifndef LIBCONFIG
	#define LIBCONFIG

#include <iostream>
#include <string>
#include <libconfig.h++>

namespace RayTracer {
    class LibConfig {
    public:
        LibConfig(const std::string &configPath);
        ~LibConfig();
        void run();
    private:
        std::string _configPath;
        libconfig::Config _cfg;
    };
}

#endif /*LIBCONFIG*/
