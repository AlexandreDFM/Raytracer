/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ADisplay.hpp
*/

#ifndef ADISPLAYMODULE_HPP_
	#define ADISPLAYMODULE_HPP_

    #include "../Interface/IDisplay.hpp"

namespace RayTracer {
    class ADisplay : public IDisplay {
        public:
            //////////////////////// Functions ////////////////////////
            void init(int width, int height, int cameraResolutionWidth, int cameraResolutionHeight, int fps, std::string &title) override;
            void update() override;
            void clear() override;
            void close() override;
            void display() override;
            bool isOpen() override;
            //////////////////////// Getters //////////////////////////
            RayTracer::EventType getEvent() override;
        protected:
            bool isOpenWindow = true;
    };
}


#endif /*ADISPLAYMODULE_HPP_*/
