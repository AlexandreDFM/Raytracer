/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Main
*/

#include "Core/Core.hpp"
#include "Exception/Usage/Usage.hpp"

int main(int argc, char **argv)
{
    Usage::CheckUsage(argc, argv);
    RayTracer::Core core(argv[1], "plugins");
    bool restart = core.run();
    while (restart) {
        core.restart();
        restart = core.run();
    }
}
