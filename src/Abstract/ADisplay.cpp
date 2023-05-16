/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ADisplay.cpp
*/

#include "ADisplay.hpp"

namespace RayTracer {
    /**
     * The function "init" initializes the game assets.
     *
     * @param gameAssets gameAssets is a constant reference to a std::map object
     * that maps characters to strings. It is likely used to store and retrieve
     * game assets such as images or sounds associated with specific characters in
     * the game. However, in the given code snippet, the parameter is not used and
     * is simply cast to void
     */
    void ADisplay::init(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title)
    {
        (void)width;
        (void)height;
        (void)cameraResolutionWidth;
        (void)cameraResolutionHeight;
        (void)fps;
        (void)title;
    }

    /**
     * This is an empty implementation of the update function in the ADisplay
     * class.
     */
    void ADisplay::update()
    {
    }

    /**
     * The function "clear" in the ADisplay class is empty and does not contain
     * any code.
     */
    void ADisplay::clear()
    {
    }

    /**
     * The function "close" in the ADisplay class has an empty body.
     */
    void ADisplay::close()
    {
    }

    /**
     * The function "display" takes a vector of Drawable objects as input and does
     * nothing with it.
     *
     * @param drawables The parameter "drawables" is a vector of objects of type
     * "Drawable". It is passed as an argument to the member function "display" of
     * the class "ADisplay". The function does not use this parameter and simply
     * casts it to void, indicating that it is not being used in the function
     */
    void ADisplay::display()
    {
    }

    bool ADisplay::isOpen()
    {
        return isOpenWindow;
    }

    /**
     * The function returns an Arcade event type of "NOTHING".
     *
     * @return an Arcade::EventType value of NOTHING.
     */
    RayTracer::EventType ADisplay::getEvent()
    {
        return RayTracer::EventType::NOTHING;
    }
}
