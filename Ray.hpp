/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-bsraytracer-roman.lopes
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            Ray();
            ~Ray();
        Math::Point3D origin;
        Math::Vector3D direction;
        protected:
        private:
    };

}
#endif /* !RAY_HPP_ */
