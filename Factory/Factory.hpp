/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-tekspice-leo.viltard
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_

    #include "../Interface/IShape.hpp"

class Factory {
    public:
        typedef std::map<std::string, std::function<std::shared_ptr<IShape>(std::string name)>> FactoryMap;
        static FactoryMap& getFactoryMap()
        {
            static FactoryMap factoryMap = {
//                    {"circle", [](std::string name) { return std::make_shared<CircleShape>(name); }},
//                    {"square", [](std::string name) { return std::make_shared<SquareShape>(name); }},
//                    {"triangle", [](std::string name) { return std::make_shared<TriangleShape>(name); }},
//                    {"rectangle", [](std::string name) { return std::make_shared<RectangleShape>(name); }},
//                    {"line", [](std::string name) { return std::make_shared<LineShape>(name); }},
//                    {"ellipse", [](std::string name) { return std::make_shared<EllipseShape>(name); }},
//                    {"polygon", [](std::string name) { return std::make_shared<PolygonShape>(name); }},
//                    {"text", [](std::string name) { return std::make_shared<TextShape>(name); }},
            };
            return factoryMap;
        };

        static std::shared_ptr<IShape> createComponent(const std::string &type, const std::string &name)
        {
            FactoryMap& factoryMap = getFactoryMap();
            auto it = factoryMap.find(type);
            if (it == factoryMap.end()) {
                std::cerr << "Error: Component " << type << " not found" << std::endl;
                exit(84);
            }
            return it->second(name);
        };
};

#endif /*FACTORY_HPP_*/
