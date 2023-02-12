#ifndef COLOR_H
#define COLOR_H

#include <map>
#include <string>

enum class Color {
    Blue, 
    Pink, 
    Yellow, 
    White, 
    Green,
};

static std::map<Color, std::string> colors = {
    {Color::White, "White"}, 
    {Color::Blue, "Blue"},
    {Color::Pink, "Pink"}, 
    {Color::Yellow, "Yellow"}, 
    {Color::Green, "Green"},
};

#endif //COLOR_H