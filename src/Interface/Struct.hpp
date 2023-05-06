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
    enum Color {
        BLACK = 1,
        RED,
        GREEN,
        BLUE,
        WHITE,
        MAGENTA,
        CYAN,
        YELLOW,
    };

    enum EventType {
        NOTHING,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        LIBPREV,
        LIBNEXT,
        GAMEPREV,
        GAMENEXT,
        CLOSE,
        RESTART,
        ACTION1,
        ACTION2,
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

    struct MenuInfo {
        std::string username;
        std::string gamePath;
        std::string libPath;
    };

    struct Drawable {
        int x;
        int y;
        Color color;
        char draw;
        enum Direction rotation = NO_DIRECTION;
        struct Rect rect = {0, 0, 0, 0};
    };

    struct DrawableText {
        int x;
        int y;
        int size;
        Color color;
        std::string text;
        std::string font;
        enum Direction rotation = NO_DIRECTION;
    };
}

#endif /*STRUCT_HPP_*/
