/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
** File description:
** Usage.cpp
*/

#include "Usage.hpp"

Usage::Error::Error(ErrorType type) noexcept
{
    _errorType = type;
}

const char *Usage::Error::what() const noexcept
{
    switch (_errorType) {
        case PATH:              return "Error: Invalid path";
        case NOT_ENOUGH_ARGS:   return "Error: Not enough arguments";
        case TOO_MANY_ARGS:     return "Error: Too many arguments";
        default:                return "Error: Unknown error";
    }
}

void Usage::DisplayUsage()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

void Usage::CheckUsage(int ac, char **av)
{
    if (ac != 2) {
        DisplayUsage();
        throw Error(Error::NOT_ENOUGH_ARGS);
    }
    if (std::string(av[1]) == "--help" || std::string(av[1]) == "-h") {
        DisplayUsage();
        exit(0);
    }
    if (!std::filesystem::exists(av[1])) {
        throw Error(Usage::Error::PATH);
    }
}
