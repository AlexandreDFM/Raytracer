/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-tekspice-leo.viltard
** File description:
** NewFactory.hpp
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_

    #include "IPrimitive.hpp"
    #include "IMaterial.hpp"
    #include "Wrapper/Wrapper.hpp"
    #include "Exception/FactoryException.hpp"
    #include "Color.hpp"

namespace RayTracer {
    class NewFactory {
        public:
            explicit NewFactory(const std::string &libPath) {
                _libPath = libPath;
                RayTracer::Wrapper wrapper;
                for (const auto &entry: std::filesystem::directory_iterator(libPath)) {
                    if (entry.path().extension() == ".so" || entry.path().extension() == ".dylib") {
                        std::cerr << "Detected library: " << entry.path() << std::endl;
                        wrapper.loadLib(entry.path());
                        auto getType = wrapper.getFunction<const char *()>("getType");
                        if (!getType)
                            throw new FactoryUnknownComponent("Invalid library: " + entry.path().string());
                        std::string type = getType();
                        std::cerr << "Detected type: " << type << std::endl;
                        if (strncmp(type.c_str(), "primitive", 9) == 0)
                            _primitivesLibraries[type.substr(10)] = entry.path().string();
                        else if (strncmp(type.c_str(), "material", 8) == 0)
                            _materialsLibraries[type.substr(9)] = entry.path().string();
                        else
                            throw new FactoryUnknownComponent("Invalid library: " + entry.path().string());
                    }
                }
            }

            ~NewFactory() = default;

            std::shared_ptr<IPrimitive> createPrimitive(const std::string &type, point3 center, double radius, std::shared_ptr<IMaterial> &material) {
                if (_primitivesLibraries.find(type) == _primitivesLibraries.end())
                    throw new FactoryUnknownComponent("Unknown primitive: " + type);
                this->_primitiveWrappers.push_back(Wrapper());
                this->_primitiveWrappers.back().loadLib(this->_primitivesLibraries[type]);
                auto entryPoint = this->_primitiveWrappers.back().getFunction<IPrimitive *(point3, double, std::shared_ptr<IMaterial>)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_primitivesLibraries[type]);
                return std::shared_ptr<IPrimitive>(entryPoint(center, radius, material));
            };

            std::shared_ptr<IMaterial> createMaterial(const std::string &type, color c, double fuzz) {
                if (_materialsLibraries.find(type) == _materialsLibraries.end())
                    throw new FactoryUnknownComponent("Unknown material: " + type);
                this->_materialWrappers.push_back(Wrapper());
                this->_materialWrappers.back().loadLib(this->_materialsLibraries[type]);
                auto entryPoint = this->_materialWrappers.back().getFunction<IMaterial *(color, double)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_materialsLibraries[type]);
                return std::shared_ptr<IMaterial>(entryPoint(point3(c.x(), c.y(), c.z()), fuzz));
            };

        private:
            std::string _libPath;
            std::map<std::string, std::string> _primitivesLibraries;
            std::map<std::string, std::string> _materialsLibraries;
            std::list<Wrapper> _primitiveWrappers;
            std::list<Wrapper> _materialWrappers;
    };
}

#endif /*FACTORY_HPP_*/
