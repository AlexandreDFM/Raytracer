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
            SFML();
            //////////////////////// Destructors ////////////////////////
            ~SFML() override = default;
            //////////////////////// Methods ////////////////////////
            void init(const std::map<char, std::string> &gameAssets) override;
            RayTracer::EventType getEvent() override;
            void update() override;
            void clear() override;
            void close() override;
            void display(std::vector<Drawable>) override;
            void display(std::vector<DrawableText>) override;

        private:
            //////////////////////// Attributes ////////////////////////
            sf::Text text;
            sf::Font font;
            sf::Event event{};
            int _spriteSize{};
            sf::Sprite sprite;
            sf::RenderWindow *window;
            std::map<char, SFMLSprite> _spriteAssets;
    };
}

#endif /* !SFML_HPP_ */
