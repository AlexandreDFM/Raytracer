/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Wrapper.hpp
*/

#ifndef WRAPPER_HPP_
	#define WRAPPER_HPP_

#include <dlfcn.h>
#include <iostream>
#include <string>

namespace RayTracer {
    class Wrapper {
    public:
        Wrapper();

        ~Wrapper();

        template<typename T>
        T *getFunction(const std::string &name)
        {
            T *function = reinterpret_cast<T *>(dlsym(_handle, name.c_str()));
            if (!function)
                std::cerr << "Cannot load symbol: " << dlerror() << '\n';
            return function;
        }

    protected:
    private:
        void *_handle = nullptr;
    };
}

#endif /*WRAPPER_HPP_*/
