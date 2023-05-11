/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Factory.hpp
*/

#ifndef FACTORY
	#define FACTORY

    #include "IShape.hpp"
    #include "IMaterial.hpp"
    #include "Primitives/Sphere.hpp"
    #include "Primitives/Plane.hpp"

    #include "Materials/Metal.hpp"
    #include "Materials/Lambertian.hpp"

namespace RayTracer {
    class Factory {
        public:
            typedef std::map<std::string, std::function<std::shared_ptr<IShape>(point3 center, double radius, std::shared_ptr<IMaterial> &material)>> FactoryMap;
            static FactoryMap& getFactoryMap()
            {
                static FactoryMap factoryMap = {
                        {"sphere", [](point3 center, double radius, std::shared_ptr<IMaterial> &material) { return std::make_shared<Sphere>(center, radius, material); }},
                        {"plane", [](point3 center, double radius, std::shared_ptr<IMaterial> &material) { return std::make_shared<Plane>(center, material); }},
                };
                return factoryMap;
            };

            static std::shared_ptr<IShape> createPrimitive(const std::string &type, point3 center, double radius, std::shared_ptr<IMaterial> &material)
            {
                FactoryMap& factoryMap = getFactoryMap();
                auto it = factoryMap.find(type);
                if (it == factoryMap.end()) {
                    std::cerr << "Error: Component " << type << " not found" << std::endl;
                    exit(84);
                }
                return it->second(center, radius, material);
            };

            typedef std::map<std::string, std::function<std::shared_ptr<IMaterial>(color color, double fuzz)>> MaterialFactoryMap;
            static MaterialFactoryMap& getMaterialFactoryMap()
            {
                static MaterialFactoryMap materialFactoryMap = {
                        {"lambertian", [](color color, double fuzz) { return std::make_shared<Lambertian>(color); }},
                        {"metal", [](color color, double fuzz) { return std::make_shared<Metal>(color, fuzz); }}
                };
                return materialFactoryMap;
            };

            static std::shared_ptr<IMaterial> createMaterial(const std::string &type, color color, double fuzz)
            {
                MaterialFactoryMap& materialFactoryMap = getMaterialFactoryMap();
                auto it = materialFactoryMap.find(type);
                if (it == materialFactoryMap.end()) {
                    std::cerr << "Error: Component " << type << " not found" << std::endl;
                    exit(84);
                }
                return it->second(color, fuzz);
            };
    };
}

#endif /*FACTORY*/
