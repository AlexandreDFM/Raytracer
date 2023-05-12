/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Factory.hpp
*/

#ifndef FACTORYEXCEPTION_HPP_
	#define FACTORYEXCEPTION_HPP_

    #include <string>
    #include <dlfcn.h>
    #include <utility>
    #include <iostream>
    #include <exception>

class FactoryUnknownComponent : public std::exception {
    public:
        explicit FactoryUnknownComponent(std::string message) : _message(std::move(message)) {};

        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); };
    private:
        const std::string _message;
};

#endif /*FACTORY_HPP_*/
