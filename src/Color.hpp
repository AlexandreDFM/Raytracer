/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Color
*/

#ifndef COLOR_H
    #define COLOR_H

    #include <iostream>
    #include "Vector3D.hpp"

namespace RayTracer {
    class Color {
        public:
            static void writeColor(std::ostream &out, Color3D &pixelColor, int samplesPerPixel)
            {
                auto r = pixelColor.x();
                auto g = pixelColor.y();
                auto b = pixelColor.z();

                // Divide the color by the number of samples and gamma-correct for gamma=2.0.
                auto scale = 1.0 / samplesPerPixel;
                r = std::sqrt(scale * r);
                g = std::sqrt(scale * g);
                b = std::sqrt(scale * b);

                // Write the translated [0,255] value of each color component.

                out << static_cast<int>(256 * Math::clamp(r, 0.0, 0.999)) << ' '
                    << static_cast<int>(256 * Math::clamp(g, 0.0, 0.999)) << ' '
                    << static_cast<int>(256 * Math::clamp(b, 0.0, 0.999)) << '\n';
            }
    };
}

#endif
