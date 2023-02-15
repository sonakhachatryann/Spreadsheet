#include "string_cell.h"

StringCell::StringCell() 
    : Cell()
    , m_value("")
{}

StringCell::StringCell(const std::string& value, const Color& color) 
    : Cell(color)
    , m_value(value)
{}

void StringCell::write(std::ofstream& out) const {
    out << "StringCell " << get_string_value() << " " << color_to_string() << '\n';
}

std::string StringCell::get_string_value() const {
    return m_value;
}

void StringCell::reset() {
    Cell::reset();
    m_value = "";
}

void StringCell::set_value(const std::string& value) {
    m_value = value;
}