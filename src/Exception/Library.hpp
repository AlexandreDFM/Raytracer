/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Library.hpp
*/

#ifndef LIBRARY_HPP_
    #define LIBRARY_HPP_

    #include <string>
    #include <dlfcn.h>
    #include <utility>
    #include <iostream>
    #include <exception>

class LibraryOpenException : public std::exception {
    public:
        explicit LibraryOpenException(std::string message) : _message(std::move(message)) {};

        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); };
    private:
        const std::string _message;
};

class UnknownLibraryException : public std::exception {
    public:
        explicit UnknownLibraryException(std::string message) : _message(std::move(message)) {};

        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); };
    private:
        const std::string _message;
};

#endif /*LIBRARY_HPP_*/
