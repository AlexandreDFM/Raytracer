/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SFML.hpp
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

    #include "ADisplay.hpp"
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>

namespace RayTracer {

    struct SFMLSprite {
        sf::Texture texture;
        sf::Sprite sprite;
    };

    class SFML : public ADisplay {
        public:
            //////////////////////// Constructors ////////////////////////
            SFML(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title);
            //////////////////////// Destructors ////////////////////////
            ~SFML() override;
            //////////////////////// Methods ////////////////////////
            void init(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title) override;
            RayTracer::EventType getEvent() override;
            void addPixel(int x, int y, double r, double g, double b, int samples_per_pixel) override;
            void update() override;
            void clear() override;
            void close() override;
            void display() override;

        private:
            //////////////////////// Attributes ////////////////////////
            sf::Image _image;
            sf::Sprite _sprite;
            sf::Event _event{};
            sf::Texture _texture;
            sf::RenderWindow *_window;
    };
}

#endif /* !SFML_HPP_ */
