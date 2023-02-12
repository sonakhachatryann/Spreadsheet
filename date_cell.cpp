#include "date_cell.h"

DateCell::DateCell(const Date& value, const Color& color) 
    : Cell(color)
    , m_value(value)
{}

void DateCell::write(std::ofstream& out) const {
    out << "DateCell " << get_string_value() << " " << color_to_string() << '\n';
}

std::string DateCell::get_string_value() const {
    std::string result = "";
    result += std::to_string(m_value.get_year()._year);
    result += '-';
    result += std::to_string(m_value.get_month()._month);
    result += '-';
    result += std::to_string(m_value.get_day()._day);
    return result;
}

void DateCell::reset() {
    Cell::reset();
    Day day(1);
    Month month(1);
    Year year(1940);
    Date date(year, month, day);
    m_value = date;
}

Date DateCell::get_value() const {
    return m_value;
}

void DateCell::set_value(const Date& value) {
    m_value = value;
}