/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace RayTracer {
    Core::Core(const std::string &configPath, const std::string &libPath) {
        this->_configHelper = new LibConfig(configPath);
        auto cameraResolutionWidth = this->_configHelper->get<int>("camera.resolution.width");
        auto cameraResolutionwHeight = this->_configHelper->get<int>("camera.resolution.height");
        auto cameraFov = this->_configHelper->get<float>("camera.fieldOfView");
        auto cameraPosX = this->_configHelper->get<float>("camera.position.x");
        auto cameraPosY = this->_configHelper->get<float>("camera.position.y");
        auto cameraPosZ = this->_configHelper->get<float>("camera.position.z");
        auto cameraRotX = this->_configHelper->get<float>("camera.rotation.x");
        auto cameraRotY = this->_configHelper->get<float>("camera.rotation.y");
        auto cameraRotZ = this->_configHelper->get<float>("camera.rotation.z");
        Math::Point3D cameraPosition = Math::Point3D(cameraPosX, cameraPosY, cameraPosZ);
        Math::Vector3D cameraRotation = Math::Vector3D(cameraRotX, cameraRotY, cameraRotZ);
        this->_camera = std::make_unique<Camera>();
        this->_camera->origin = cameraPosition;
        // Créer les objets
        Factory factory(libPath);
        std::shared_ptr<IShape>sphere = factory.createComponent("Sphere", "sphere1");
        // Créer les lumières
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
