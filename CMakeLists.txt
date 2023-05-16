cmake_minimum_required(VERSION 3.16)

project(raytracer)

include_directories(
        src
        src/Interface
        src/Abstract
)

find_package(SFML 2.5 COMPONENTS window system graphics audio REQUIRED)
find_library(libconfig libconfig)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../plugins")
set(CMAKE_SHARED_LIBRARY_PREFIX "raytracer_")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

#Threads
add_library("threads" SHARED src/Abstract/AThread.cpp src/Abstract/AThread.hpp src/Interface/IThread.hpp)
set_target_properties("threads" PROPERTIES PREFIX "raytracer_")
target_link_libraries("threads" -Ofast)

# Graphics libraries
# SFML
add_library("sfml" SHARED src/Abstract/ADisplay.cpp src/Abstract/ADisplay.hpp src/Libraries/Graphical/SFML/SFML.cpp src/Libraries/Graphical/SFML/SFML.hpp)
set_target_properties("sfml" PROPERTIES PREFIX "raytracer_")
target_link_libraries("sfml" -Ofast sfml-graphics sfml-window sfml-system sfml-audio)


# Primitives libraries
# Sphere
add_library("sphere" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Primitives/Sphere.cpp src/Primitives/Sphere.hpp)
set_target_properties("sphere" PROPERTIES PREFIX "raytracer_")
target_link_libraries("sphere" -Ofast)

add_library("plane" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Primitives/Plane.cpp src/Primitives/Plane.hpp)
set_target_properties("plane" PROPERTIES PREFIX "raytracer_")
target_link_libraries("plane" -Ofast)

# Rectangle
add_library("rectangle" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Math/AxisAlignement.hpp src/Primitives/Rectangle.cpp src/Primitives/Rectangle.hpp)
set_target_properties("rectangle" PROPERTIES PREFIX "raytracer_")
target_link_libraries("rectangle" -Ofast)

# Cylinder
add_library("cylinder" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Math/AxisAlignement.hpp src/Primitives/Cylinder.cpp src/Primitives/Cylinder.hpp)
set_target_properties("cylinder" PROPERTIES PREFIX "raytracer_")
target_link_libraries("cylinder" -Ofast)

# Cone
add_library("cone" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Math/AxisAlignement.hpp src/Primitives/Cone.cpp src/Primitives/Cone.hpp)
set_target_properties("cone" PROPERTIES PREFIX "raytracer_")
target_link_libraries("cone" -Ofast)

#Materials libraries
# Lambertian
add_library("lambertian" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/Lambertian.cpp src/Materials/Lambertian.hpp src/Texture/SolidColorTexture.cpp src/Texture/SolidColorTexture.hpp)
set_target_properties("lambertian" PROPERTIES PREFIX "raytracer_")
target_link_libraries("lambertian" -Ofast)

# Metal
add_library("metal" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/Metal.cpp src/Materials/Metal.hpp)
set_target_properties("metal" PROPERTIES PREFIX "raytracer_")
target_link_libraries("metal" -Ofast)

# Dielectric
add_library("dielectric" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/Dielectric.cpp src/Materials/Dielectric.hpp)
set_target_properties("dielectric" PROPERTIES PREFIX "raytracer_")
target_link_libraries("dielectric" -Ofast)

# Diffuse Light
add_library("diffuse_light" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/DiffuseLight.cpp src/Materials/DiffuseLight.hpp)
set_target_properties("diffuse_light" PROPERTIES PREFIX "raytracer_")
target_link_libraries("diffuse_light" -Ofast)


# Lights libraries
# Point
add_library("point" SHARED src/Abstract/ALight.cpp src/Abstract/ALight.hpp src/Interface/ILight.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Lights/Point.cpp src/Lights/Point.hpp)
set_target_properties("point" PROPERTIES PREFIX "raytracer_")
target_link_libraries("point" -Ofast)

# Directional
add_library("directional" SHARED src/Abstract/ALight.cpp src/Abstract/ALight.hpp src/Interface/ILight.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Lights/Directional.hpp src/Lights/Directional.cpp)
set_target_properties("directional" PROPERTIES PREFIX "raytracer_")
target_link_libraries("directional" -Ofast)

# Ambient
add_library("ambient" SHARED src/Abstract/ALight.cpp src/Abstract/ALight.hpp src/Interface/ILight.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Lights/Ambient.hpp src/Lights/Ambient.cpp)
set_target_properties("ambient" PROPERTIES PREFIX "raytracer_")
target_link_libraries("ambient" -Ofast)


# Textures libraries
# Solid Color
#add_library("solid_color" SHARED src/Interface/ITexture.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Texture/SolidColorTexture.cpp src/Texture/SolidColorTexture.hpp)
#set_target_properties("solid_color" PROPERTIES PREFIX "raytracer_")

# Checker
add_library("checker" SHARED src/Texture/SolidColorTexture.hpp src/Texture/SolidColorTexture.cpp src/Interface/ITexture.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Texture/CheckerTexture.cpp src/Texture/CheckerTexture.hpp)
set_target_properties("checker" PROPERTIES PREFIX "raytracer_")
target_link_libraries("checker" -Ofast)

# Noise
add_library("noise" SHARED src/Texture/SolidColorTexture.hpp src/Texture/SolidColorTexture.cpp src/Interface/ITexture.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Texture/NoiseTexture.cpp src/Texture/NoiseTexture.hpp)
set_target_properties("noise" PROPERTIES PREFIX "raytracer_")
target_link_libraries("noise" -Ofast)


add_executable(
        raytracer
        src/Main.cpp
        src/Interface/IPrimitive.hpp
        src/Abstract/APrimitive.cpp
        src/Abstract/APrimitive.hpp
        src/Exception/Usage/Usage.cpp
        src/Exception/Usage/Usage.hpp
        src/Camera.cpp
        src/Camera.hpp
        src/Ray.cpp
        src/Ray.hpp
        src/Color.hpp
        src/Vector3D.cpp
        src/Vector3D.hpp
        src/Primitives/Sphere.hpp
        src/Wrapper/Wrapper.hpp
        src/Factory/Factory.hpp
        src/Config/LibConfig.hpp
        src/Config/LibConfig.cpp
        src/Exception/Library.hpp
        src/Exception/FactoryException.hpp
        src/Wrapper/Wrapper.cpp
        src/Abstract/ADisplay.cpp
        src/HittableList.hpp
        src/Math/Math.cpp
        src/Math/Math.hpp
        src/Core/Core.cpp
        src/Interface/ILight.hpp)

target_link_libraries(raytracer -Ofast sfml-graphics sfml-window sfml-system sfml-audio "dl" config++)
