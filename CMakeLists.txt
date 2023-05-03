cmake_minimum_required(VERSION 3.16)

project(arcade)

include_directories(
        src/Interface
)

find_package(SFML 2.5 COMPONENTS window system graphics audio REQUIRED)
find_library(libconfig libconfig)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_SHARED_LIBRARY_PREFIX "raytracer_")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

# Primitives libraries

# Sphere
add_library("sphere" SHARED src/Primitives/Sphere.cpp src/Primitives/Sphere.hpp)
set_target_properties("sphere" PROPERTIES PREFIX "raytracer_")

add_executable( raytracer
        src/Main.cpp
        src/Interface/IShape.hpp
        src/Abstract/AShape.cpp
        src/Abstract/AShape.hpp
        src/Exception/Usage/Usage.cpp
        src/Exception/Usage/Usage.hpp
        src/Camera.cpp
        src/Camera.hpp
        src/Point3D.cpp
        src/Point3D.hpp
        src/Ray.cpp
        src/Ray.hpp
        src/Rectangle3D.cpp
        src/Rectangle3D.hpp
        src/Vector3D.cpp
        src/Vector3D.hpp
        src/Wrapper/Wrapper.hpp
        src/Factory/Factory.hpp
        src/Config/LibConfig.hpp
        src/Config/LibConfig.cpp
        src/Core/Core.cpp
        src/Core/Core.hpp
        src/Exception/Library.hpp
        src/Exception/FactoryException.hpp src/Wrapper/Wrapper.cpp)
target_link_libraries(raytracer sfml-graphics sfml-window sfml-system sfml-audio "dl" config++)
