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
            virtual void init(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title) = 0;
            virtual void update() = 0;
            virtual void close() = 0;
            virtual void clear() = 0;
            virtual void display() = 0;
            virtual bool isOpen() = 0;
            virtual void addPixel(int x, int y, double r, double g, double b, int samples_per_pixel) = 0;
            //////////////////////// Getters //////////////////////////
            virtual RayTracer::EventType getEvent() = 0;
    };
}

#endif /*IDISPLAY*/
