/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IDisplay.hpp
*/

#ifndef IDISPLAY
	#define IDISPLAY

    #include "Struct.hpp"

namespace RayTracer {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            //////////////////////// Functions ////////////////////////
            virtual void init(const std::map<char, std::string>& gameAssets) = 0;
            virtual void update() = 0;
            virtual void close() = 0;
            virtual void clear() = 0;
            virtual void display(std::vector<Drawable>) = 0;
            virtual void display(std::vector<DrawableText>) = 0;
            //////////////////////// Getters //////////////////////////
            virtual RayTracer::EventType getEvent() = 0;
    };
}

#endif /*IDISPLAY*/
