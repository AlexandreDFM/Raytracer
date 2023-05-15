/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Math.hpp
*/

#ifndef MATH_HPP_
	#define MATH_HPP_

    #include <cmath>
    #include <limits>
    #include <memory>

class Math {
    public:
        Math() = default;
        ~Math() = default;
        constexpr static const double infinity = std::numeric_limits<double>::infinity();
        constexpr static const double pi = 3.1415926535897932385;
        static double degrees_to_radians(double degrees) {
            return degrees * M_PI / 180.0;
        }
        static double random_double() {
            // Returns a random real in [0,1).
            return rand() / (RAND_MAX + 1.0);
        }
        static double random_double(double min, double max) {
            // Returns a random real in [min,max).
            return min + (max-min)*random_double();
        }
        static double clamp(double x, double min, double max) {
            if (x < min) return min;
            if (x > max) return max;
            return x;
        }
        static int randomInt(int min, int max) {
            // Returns a random integer in [min,max].
            return static_cast<int>(random_double(min, max+1));
        }
};

#endif /*MATH_HPP_*/
