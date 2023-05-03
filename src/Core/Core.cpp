/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace RayTracer {
    Core::Core(const std::string &configPath) {
        // Charger le fichier de config
        this->_configHelper = new LibConfig(configPath);

        // Créer les objets
        // Créer les lumières
        // Créer les caméras
    }

    Core::~Core() {
        // de
    }

    void Core::run() {
        // Boucle de rendu
        // Pour chaque caméra
        //  Pour chaque pixel
        //      Pour chaque objet
        //          Calculer l'intersection
        //          Si intersection et distance < distance min alors
        //              distance min = distance
        //              objet le plus proche = objet
        //      Si objet le plus proche alors
        //          Calculer la couleur
        //          Dessiner le pixel
        //  Afficher l'image
    }
}
