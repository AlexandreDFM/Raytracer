/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** LibConfig.hpp
*/

#ifndef LIBCONFIG
	#define LIBCONFIG

    #include <string>
    #include <iostream>
    #include <libconfig.h++>

namespace RayTracer {
    class LibConfig {
        public:
            explicit LibConfig(const std::string &configPath);
            ~LibConfig() = default;
            template<typename T>
            T get(const std::string &path) {
                T value;
                try {
                    this->_cfg.lookupValue(path, value);
                    return value;
                } catch (const libconfig::SettingNotFoundException &nfex) {
                    std::cerr << "No '" << path << "' setting in configuration file." << std::endl;
                }
                return T();
            }
            int getLength(const std::string &path) {
                try {
                    this->_cfg.lookup(path);
                    return this->_cfg.lookup(path).getLength();
                } catch (const libconfig::SettingNotFoundException &nfex) {
                    std::cerr << "No '" << path << "' setting in configuration file." << std::endl;
                }
                return 0;
            }
            template<typename T>
            T getLineValueFromArray(const std::string& pathArray, const std::string& path, int index) {
                T value;
                try {
                    const libconfig::Setting& array = this->_cfg.lookup(pathArray);
                    const libconfig::Setting& line = array[index];
                    const libconfig::Setting& valueSetting = line.lookup(path);
                    value = static_cast<T>(valueSetting);
                } catch (const libconfig::SettingNotFoundException& nfex) {
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
