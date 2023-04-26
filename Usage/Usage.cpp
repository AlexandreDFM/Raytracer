/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Usage.cpp
*/

#include "Usage.hpp"

Usage::Error::Error(ErrorType type)
{
    switch (type) {
        case LIB:
            _message = "Error: Library not found";
            break;
        case GAME:
            _message = "Error: Game not found";
            break;
    }
}

const std::string &Usage::Error::what() const
{
    return _message;
}

void Usage::DisplayUsage()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

void Usage::CheckUsage(int ac, char **av)
{
    if (ac != 2) {
        Usage::DisplayUsage();
        exit(84);
//        throw Usage::Error(Usage::Error::LIB);
    }
    if (std::string(av[1]) == "--help") {
        DisplayUsage();
        exit (0);
    }
}

void Usage::CheckLib(char **av)
{
    std::string lib = av[1];
    if (lib.find(".so") == std::string::npos) {
        DisplayUsage(); throw Usage::Error(Usage::Error::LIB);
    }
}
