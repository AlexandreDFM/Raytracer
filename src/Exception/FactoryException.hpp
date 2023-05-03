/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Factory.hpp
*/
#ifndef FACTORYEXCEPTION_HPP_
	#define FACTORYEXCEPTION_HPP_

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <exception>

class FactoryUnknownComponent : public std::exception {
    public:
        FactoryUnknownComponent(const std::string &message) : _message(message) {};

        ~FactoryUnknownComponent() = default;

        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); };
    private:
        const std::string _message;
};

#endif /*FACTORY_HPP_*/
