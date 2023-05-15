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
            virtual ~IThread() = default;
    };
}

#endif /*THREAD*/
