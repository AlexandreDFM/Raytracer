/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

namespace RayTracer {
    /**
     * This is a constructor for the SFML class that initializes the window and
     * event variables.
     */
    SFML::SFML(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title)
    {
        this->_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
        this->_window->setFramerateLimit(fps);
        this->_event = sf::Event();

        this->_image.create(cameraResolutionWidth, cameraResolutionHeight, {128, 128, 128});
        this->_texture.loadFromImage(this->_image);
        this->_sprite.setTexture(this->_texture);

        float x = (float) width / 2 - (float) cameraResolutionWidth / 2;
        float y = (float) height / 2 - (float) cameraResolutionHeight / 2;
        this->_sprite.setPosition(x, y);
    }

    SFML::~SFML()
    {
        this->_window->close();
        delete this->_window;
    }

    /**
     * The function initializes the SFML window and loads game assets such as
     * textures and sprites.
     *
     * @param gameAssets gameAssets is a std::map that contains pairs of
     * characters and strings. The characters represent the keys and the strings
     * represent the file paths to the corresponding sprite assets. These sprite
     * assets are loaded into textures and sprites using the SFML library.
     */
    void SFML::init(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title)
    {
        this->_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
        this->_window->setFramerateLimit(fps);
        this->_event = sf::Event();
        this->_image.create(cameraResolutionWidth, cameraResolutionHeight, {128, 128, 128});
        this->_texture.loadFromImage(this->_image);
        this->_sprite.setTexture(this->_texture);

        float x = (float) width / 2 - (float) cameraResolutionWidth / 2;
        float y = (float) height / 2 - (float) cameraResolutionHeight / 2;
        this->_sprite.setPosition(x, y);
    }

    /**
     * This function returns the type of event that occurred in a SFML window.
     *
     * @return an EventType enum value based on the type of event that is being
     * polled from the SFML window. If the event is a closed event, it returns
     * EventType::CLOSE. If the event is a key press event, it checks which key
     * was pressed and returns the corresponding EventType value. If no event is
     * being polled, it returns EventType::NOTHING.
     */
    EventType SFML::getEvent()
    {
        while (this->_window->pollEvent(this->_event)) {
            if (this->_event.type == sf::Event::Closed) {
                this->isOpenWindow = false;
                return EventType::CLOSE;
            }
            if (this->_event.type == sf::Event::KeyPressed) {
                switch (this->_event.key.code) {
                    case sf::Keyboard::Escape:
                        this->isOpenWindow = false;
                        return EventType::CLOSE;
                    case sf::Keyboard::Space:  return EventType::PAUSE;
                    case sf::Keyboard::R:      return EventType::RESTART;
                    case sf::Keyboard::L:      return EventType::LIBPREV;
                    case sf::Keyboard::M:      return EventType::LIBNEXT;
                    case sf::Keyboard::T:
                        this->_image.saveToFile("screenshots/screenshot.png");
                        return EventType::SAVE;
                    default:                   return EventType::NOTHING;
                }
            }
        }
        return EventType::NOTHING;
    }

    void SFML::addPixel(int x, int y, double r, double g, double b, int samples_per_pixel)
    {
        auto scale = 1.0 / samples_per_pixel;

        r = std::sqrt(scale * r);
        g = std::sqrt(scale * g);
        b = std::sqrt(scale * b);

        r = 256 * std::clamp(r, 0.0, 0.999);
        g = 256 * std::clamp(g, 0.0, 0.999);
        b = 256 * std::clamp(b, 0.0, 0.999);

        this->_image.setPixel(x, y, sf::Color((int) r, (int) g, (int) b));
    }

    void SFML::display()
    {
        this->_texture.loadFromImage(this->_image);
        this->_sprite.setTexture(this->_texture);
        this->_window->draw(this->_sprite);
    }

    /**
     * The SFML update function displays the window.
     */
    void SFML::update()
    {
        this->_window->display();
    }

    /**
     * The SFML clear function clears the window with a black color.
     */
    void SFML::clear()
    {
        this->_window->clear(sf::Color::Black);
        // Create Grey Transparent Background
        sf::Color color = sf::Color(128, 128, 128, 50);
        this->_window->clear(color);
    }

    /**
     * This function closes the SFML window and deletes the window object.
     */
    void SFML::close()
    {
        this->_window->close();
        delete this->_window;
    }

    /* The `extern "C"` block is used to specify that the functions inside it
    should be compiled using C linkage instead of C++ linkage. This is
    necessary when creating a C++ library that needs to be used by a C program
    or a program written in another language that uses C linkage. In this case,
    the `entryPoint()` and `getType()` functions are declared as C functions
    that return a pointer to `ADisplay` and a character array, respectively.
    This allows the functions to be called from a C program or a program
    written in another language that uses C linkage. */
    extern "C" {
        /**
         * The function returns a pointer to an instance of the SFML class, which
         * is a display object.
         *
         * @return A pointer to an object of type `ADisplay` that is created using
         * the `new` operator and initialized with a `SFML` object.
         */
        ADisplay *entryPoint(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string title)
        {
            return new SFML(width, height, cameraResolutionWidth, cameraResolutionHeight, fps, title);
        }

        /**
         * The function returns a string indicating the type of library used,
         * which is "libSFML".
         *
         * @return A string literal "libSFML" is being returned as a pointer to a
         * character array.
         */
        char *getType()
        {
            return (char *) "display_SFML";
        }
    }
}
