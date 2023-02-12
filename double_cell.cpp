#include "double_cell.h"

DoubleCell::DoubleCell() 
    : Cell()
    , m_value(0)
{}

DoubleCell::DoubleCell(double value, const Color& color) 
    : Cell(color)
    , m_value(value)
{}

void DoubleCell::write(std::ofstream& out) const {
    out << "DoubleCell " << get_string_value() << " " << color_to_string() << '\n';
}

std::string DoubleCell::get_string_value() const {
    return std::to_string(m_value);
}

void DoubleCell::reset() {
    Cell::reset();
    m_value = 0;
}

double DoubleCell::get_value() const {
    return m_value;
}

void DoubleCell::set_value(double value) {
    m_value = value;
}