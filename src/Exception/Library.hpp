/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Library.hpp
*/
#ifndef LIBRARY_HPP_
#define LIBRARY_HPP_

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <exception>

class LibraryOpenException : public std::exception {
    public:
        LibraryOpenException(const std::string &message) : _message(message) {};

        ~LibraryOpenException() = default;

        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); };
    private:
        const std::string _message;
};

class UnknownLibraryException : public std::exception {
    public:
        UnknownLibraryException(const std::string &message) : _message(message) {};

        ~UnknownLibraryException() = default;

        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); };
    private:
        const std::string _message;
};

#endif /*LIBRARY_HPP_*/
