/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Wrapper.cpp
*/

#include "Wrapper.hpp"

namespace RayTracer {

    Wrapper::~Wrapper()
    {
        if (this->_handle)
            dlclose(this->_handle);
    }

    void Wrapper::loadLib(const std::string &path)
    {
        if (path.empty())
            throw LibraryOpenException("Library path is empty");
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!_handle)
            throw LibraryOpenException("Cannot open library");
    }
}
