/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Factory.hpp
*/

#ifndef FACTORY
	#define FACTORY

    #include "IShape.hpp"
    #include "Material.hpp"
    #include "Primitives/Sphere.hpp"

namespace RayTracer {
    class Factory {
        public:
            typedef std::map<std::string, std::function<std::shared_ptr<IShape>(point3 center, double radius, std::shared_ptr<IMaterial> &material)>> FactoryMap;
            static FactoryMap& getFactoryMap()
            {
                static FactoryMap factoryMap = {
                        {"sphere", [](point3 center, double radius, std::shared_ptr<IMaterial> &material) { return std::make_shared<Sphere>(center, radius, material); }},
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
    };
}

#endif /*FACTORY*/
