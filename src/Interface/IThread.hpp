/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Thread.hpp
*/

#ifndef THREAD
	#define THREAD

    #include <thread>

namespace RayTracer {
    class IThread {
        public:
            virtual void lock() = 0;
            virtual void unlock() = 0;
            virtual void trylock() = 0;
    };
}

#endif /*THREAD*/
