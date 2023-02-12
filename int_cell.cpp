#include "int_cell.h"

IntCell::IntCell() 
    : Cell()
    , m_value(0)
{}

IntCell::IntCell(int value, const Color& color) 
    : Cell(color)
    , m_value(value)
{}

void IntCell::write(std::ofstream& out) const {
    out << "IntCell " << get_string_value() << " " << color_to_string() << '\n';
}

std::string IntCell::get_string_value() const {
    return std::to_string(m_value);
}

void IntCell::reset() {
    Cell::reset();
    m_value = 0;
}

int IntCell::get_value() const {
    return m_value;
}

void IntCell::set_value(int value) {
    m_value = value;
}