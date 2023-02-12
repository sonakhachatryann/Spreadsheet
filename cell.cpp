#include "cell.h"

Cell::Cell() 
    : m_color(Color::White)
{}

Cell::Cell(const Color& color) 
    : m_color(color)
{}

Color Cell::get_color() const {
    return m_color;
}

void Cell::set_color(const Color& color) {
    m_color = color;
}

void Cell::reset() {
    m_color = Color::White;
}

std::string Cell::color_to_string() const {
    return colors[m_color];
}