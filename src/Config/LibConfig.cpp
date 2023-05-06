/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** LibConfig.cpp
*/

#include "LibConfig.hpp"

namespace RayTracer {
    LibConfig::LibConfig(const std::string &configPath) {
        try {
            this->_cfg.readFile(configPath.c_str());
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                      << " - " << pex.getError() << std::endl;
        }
    }
}
