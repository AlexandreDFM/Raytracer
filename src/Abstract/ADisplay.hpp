/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ADisplay.hpp
*/

#ifndef ADISPLAYMODULE_HPP_
	#define ADISPLAYMODULE_HPP_

    #include "IDisplay.hpp"

namespace RayTracer {
    class ADisplay : public IDisplay {
        public:
            //////////////////////// Functions ////////////////////////
            void init(const std::map<char, std::string>& gameAssets) override;
            void update() override;
            void clear() override;
            void close() override;
            void display(std::vector<Drawable> drawables) override;
            void display(std::vector<DrawableText> drawables) override;
            //////////////////////// Getters //////////////////////////
            RayTracer::EventType getEvent() override;
    };
}


#endif /*ADISPLAYMODULE_HPP_*/
