/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-tekspice-leo.viltard
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_

    #include "Color.hpp"
    #include "ILight.hpp"
    #include "ITexture.hpp"
    #include "IMaterial.hpp"
    #include "IPrimitive.hpp"
    #include "Wrapper/Wrapper.hpp"
    #include "Exception/FactoryException.hpp"

namespace RayTracer {
    class Factory {
        public:
            explicit Factory(const std::string &libPath) {
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
                        else if (strncmp(type.c_str(), "light", 5) == 0)
                            _lightsLibraries[type.substr(6)] = entry.path().string();
                        else if (strncmp(type.c_str(), "display", 7) == 0)
                            _displaysLibraries[type.substr(8)] = entry.path().string();
                        else if (strncmp(type.c_str(), "texture", 7) == 0)
                            _texturesLibraries[type.substr(8)] = entry.path().string();
                        else if (strncmp(type.c_str(), "thread", 6) == 0)
                            std::cout << "thread" << std::endl;
                        else
                            throw new FactoryUnknownComponent("Invalid library: " + entry.path().string());
                    }
                }
            }

            ~Factory() = default;

            std::shared_ptr<IPrimitive> createPrimitive(const std::string &type, Point3D center, std::vector<double> variables, std::shared_ptr<IMaterial> &material) {
                if (_primitivesLibraries.find(type) == _primitivesLibraries.end())
                    throw new FactoryUnknownComponent("Unknown primitive: " + type);
                this->_primitiveWrappers.push_back(Wrapper());
                this->_primitiveWrappers.back().loadLib(this->_primitivesLibraries[type]);
                auto entryPoint = this->_primitiveWrappers.back().getFunction<IPrimitive *(Point3D, std::vector<double>, std::shared_ptr<IMaterial>)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_primitivesLibraries[type]);
                return std::shared_ptr<IPrimitive>(entryPoint(center, variables, material));
            };

            std::shared_ptr<IMaterial> createMaterial(const std::string &type, Color3D c, double fuzz) {
                if (_materialsLibraries.find(type) == _materialsLibraries.end())
                    throw new FactoryUnknownComponent("Unknown material: " + type);
                this->_materialWrappers.push_back(Wrapper());
                this->_materialWrappers.back().loadLib(this->_materialsLibraries[type]);
                auto entryPoint = this->_materialWrappers.back().getFunction<IMaterial *(Color3D, double)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_materialsLibraries[type]);
                return std::shared_ptr<IMaterial>(entryPoint(Point3D(c.x(), c.y(), c.z()), fuzz));
            };

            std::shared_ptr<IMaterial> createTextureMaterial(const std::string &type, std::shared_ptr<ITexture> &texture, double fuzz) {
                if (_materialsLibraries.find(type) == _materialsLibraries.end())
                    throw new FactoryUnknownComponent("Unknown material: " + type);
                this->_materialWrappers.push_back(Wrapper());
                this->_materialWrappers.back().loadLib(this->_materialsLibraries[type]);
                auto textureEntryPoint = this->_materialWrappers.back().getFunction<IMaterial *(std::shared_ptr<ITexture>, double)>("textureEntryPoint");
                if (!textureEntryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_materialsLibraries[type]);
                return std::shared_ptr<IMaterial>(textureEntryPoint(texture, fuzz));
            };

            std::shared_ptr<ILight> createLight(const std::string &type, Point3D pos, Point3D direction, Color3D clr) {
                if (_lightsLibraries.find(type) == _lightsLibraries.end())
                    throw new FactoryUnknownComponent("Unknown light: " + type);
                this->_lightWrappers.push_back(Wrapper());
                this->_lightWrappers.back().loadLib(this->_lightsLibraries[type]);
                auto entryPoint = this->_lightWrappers.back().getFunction<ILight *(Point3D, Point3D, Color3D)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_lightsLibraries[type]);
                return std::shared_ptr<ILight>(entryPoint(pos, direction, clr));
            };

            std::shared_ptr<ITexture> createTexture(const std::string &type, std::vector<double> variables) {
                if (_texturesLibraries.find(type) == _texturesLibraries.end())
                    throw new FactoryUnknownComponent("Unknown texture: " + type);
                this->_textureWrappers.push_back(Wrapper());
                this->_textureWrappers.back().loadLib(this->_texturesLibraries[type]);
                auto entryPoint = this->_textureWrappers.back().getFunction<ITexture *(std::vector<double>)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_texturesLibraries[type]);
                return std::shared_ptr<ITexture>(entryPoint(variables));
            };

            std::shared_ptr<IDisplay> createDisplay(const std::string &type, int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title) {
                if (_displaysLibraries.find(type) == _displaysLibraries.end())
                    throw new FactoryUnknownComponent("Unknown material: " + type);
                this->_displayWrappers.push_back(Wrapper());
                this->_displayWrappers.back().loadLib(this->_displaysLibraries[type]);
                auto entryPoint = this->_displayWrappers.back().getFunction<IDisplay *(int, int, int, int, int, std::string)>("entryPoint");
                if (!entryPoint)
                    throw new FactoryUnknownComponent("Invalid library: " + this->_displaysLibraries[type]);
                return std::shared_ptr<IDisplay>(entryPoint(width, height, cameraResolutionWidth, cameraResolutionHeight, fps, title));
            };

        private:
            std::string _libPath;
            std::map<std::string, std::string> _primitivesLibraries;
            std::map<std::string, std::string> _materialsLibraries;
            std::map<std::string, std::string> _texturesLibraries;
            std::map<std::string, std::string> _displaysLibraries;
            std::map<std::string, std::string> _lightsLibraries;
            std::list<Wrapper> _primitiveWrappers;
            std::list<Wrapper> _materialWrappers;
            std::list<Wrapper> _textureWrappers;
            std::list<Wrapper> _displayWrappers;
            std::list<Wrapper> _lightWrappers;
    };
}

#endif /*FACTORY_HPP_*/
