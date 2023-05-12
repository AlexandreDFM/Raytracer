/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Struct.hpp
*/

#ifndef STRUCT
    #define STRUCT

    #include <ios>
    #include <map>
    #include <list>
    #include <cmath>
    #include <vector>
    #include <memory>
    #include <string>
    #include <cstring>
    #include <iostream>
    #include <iterator>
    #include <algorithm>
    #include <filesystem>
    #include <functional>

namespace RayTracer {
    enum EventType {
        NOTHING,
        LIBPREV,
        LIBNEXT,
        CLOSE,
        RESTART,
        PAUSE,
        MENU,
        SAVE
    };

    enum Direction {
        NO_DIRECTION,
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    struct Rect {
        int left;
        int top;
        int width;
        int height;
    };

    struct Drawable {
        int x;
        int y;
        char draw;
        enum Direction rotation = NO_DIRECTION;
        struct Rect rect = {0, 0, 0, 0};
    };

    struct DrawableText {
        int x;
        int y;
        int size;
        std::string text;
        std::string font;
        enum Direction rotation = NO_DIRECTION;
    };
}

#endif /*STRUCT_HPP_*/
