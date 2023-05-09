/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-tekspice-leo.viltard
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_


    #include "IShape.hpp"
    #include "../Wrapper/Wrapper.hpp"
    #include "../Exception/FactoryException.hpp"

namespace RayTracer {
    class Factory {
        public:
            explicit Factory(const std::string &libPath) {
                _libPath = libPath;
                RayTracer::Wrapper wrapper;
                for (const auto &entry: std::filesystem::directory_iterator(libPath)) {
                    if (entry.path().extension() == ".so" || entry.path().extension() == ".dylib") {
                        std::cout << "Loading library: " << entry.path() << std::endl;
                        wrapper.loadLib(entry.path());
                        auto entryPoint = wrapper.getFunction < std::shared_ptr<IShape>(
                        const std::string &)>("entryPoint");
                        auto getType = wrapper.getFunction<const char *()>("getType");
                        if (!entryPoint || !getType)
                            throw new FactoryUnknownComponent("Invalid library: " + entry.path().string());
                        std::string type = getType();
                        std::cout << "Loaded type: " << type << std::endl;
                        this->_factoryMap[type] = entryPoint;
                    }
                }
            }

            ~Factory() = default;

            std::shared_ptr<IShape> createComponent(const std::string &type, const std::string &name) {
                auto it = this->_factoryMap.find(type);
                if (it == this->_factoryMap.end()) {
                    throw new FactoryUnknownComponent("Unknown type: " + type);
                }
                return it->second(name);
            };

        private:
            std::string _libPath;
            std::map<std::string, std::function<std::shared_ptr<IShape>(const std::string &)>> _factoryMap;
    };
}

#endif /*FACTORY_HPP_*/
