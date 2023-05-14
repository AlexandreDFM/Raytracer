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
add_library("threads" SHARED src/Abstract/AThread.cpp src/Abstract/AThread.hpp src/Interface/IThread.cpp src/Interface/IThread.hpp)
set_target_properties("threads" PROPERTIES PREFIX "raytracer_")

# Graphics libraries
# SFML
add_library("sfml" SHARED src/Abstract/ADisplay.cpp src/Abstract/ADisplay.hpp src/Libraries/Graphical/SFML/SFML.cpp src/Libraries/Graphical/SFML/SFML.hpp)
set_target_properties("sfml" PROPERTIES PREFIX "raytracer_")
target_link_libraries("sfml" sfml-graphics sfml-window sfml-system sfml-audio)


# Primitives libraries
# Sphere
add_library("sphere" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Primitives/Sphere.cpp src/Primitives/Sphere.hpp)
set_target_properties("sphere" PROPERTIES PREFIX "raytracer_")

add_library("plane" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Primitives/Plane.cpp src/Primitives/Plane.hpp)
set_target_properties("plane" PROPERTIES PREFIX "raytracer_")

# Rectangle
add_library("rectangle" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Math/AxisAlignement.hpp src/Primitives/Rectangle.cpp src/Primitives/Rectangle.hpp)
set_target_properties("rectangle" PROPERTIES PREFIX "raytracer_")

# Cylinder
add_library("cylinder" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Math/AxisAlignement.hpp src/Primitives/Cylinder.cpp src/Primitives/Cylinder.hpp)
set_target_properties("cylinder" PROPERTIES PREFIX "raytracer_")

# Cone
add_library("cone" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/APrimitive.cpp src/Abstract/APrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Math/AxisAlignement.hpp src/Primitives/Cone.cpp src/Primitives/Cone.hpp)
set_target_properties("cone" PROPERTIES PREFIX "raytracer_")


#Materials libraries
# Lambertian
add_library("lambertian" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/Lambertian.cpp src/Materials/Lambertian.hpp)
set_target_properties("lambertian" PROPERTIES PREFIX "raytracer_")

# Metal
add_library("metal" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/Metal.cpp src/Materials/Metal.hpp)
set_target_properties("metal" PROPERTIES PREFIX "raytracer_")

# Dielectric
add_library("dielectric" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/Dielectric.cpp src/Materials/Dielectric.hpp)
set_target_properties("dielectric" PROPERTIES PREFIX "raytracer_")

# Diffuse Light
add_library("diffuse_light" SHARED src/Ray.cpp src/Ray.hpp src/Abstract/AMaterial.cpp src/Abstract/AMaterial.hpp src/Interface/IPrimitive.hpp src/Interface/IMaterial.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Materials/DiffuseLight.cpp src/Materials/DiffuseLight.hpp)
set_target_properties("diffuse_light" PROPERTIES PREFIX "raytracer_")


# Lights libraries
# Point
add_library("point" SHARED src/Abstract/ALight.cpp src/Abstract/ALight.hpp src/Interface/ILight.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Lights/Point.cpp src/Lights/Point.hpp)
set_target_properties("point" PROPERTIES PREFIX "raytracer_")

# Directional
add_library("directional" SHARED src/Abstract/ALight.cpp src/Abstract/ALight.hpp src/Interface/ILight.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Lights/Directional.hpp src/Lights/Directional.cpp)
set_target_properties("directional" PROPERTIES PREFIX "raytracer_")

# Ambient
add_library("ambient" SHARED src/Abstract/ALight.cpp src/Abstract/ALight.hpp src/Interface/ILight.hpp src/Vector3D.hpp src/Vector3D.cpp src/Color.hpp src/Lights/Ambient.hpp src/Lights/Ambient.cpp)
set_target_properties("ambient" PROPERTIES PREFIX "raytracer_")

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
        src/Rectangle3D.cpp
        src/Rectangle3D.hpp
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
