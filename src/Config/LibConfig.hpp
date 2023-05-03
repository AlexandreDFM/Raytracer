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
        template<typename T>
        T get(const std::string &path) {
            T value;
            try {
                this->_cfg.lookupValue(path, value);
            } catch (const libconfig::SettingNotFoundException &nfex) {
                std::cerr << "No '" << path << "' setting in configuration file." << std::endl;
            }
            return value;
        }
    private:
        std::string _configPath;
        libconfig::Config _cfg;
    };
}

#endif /*LIBCONFIG*/
