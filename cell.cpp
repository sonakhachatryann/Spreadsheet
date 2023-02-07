#include "cell.h"

Cell::Cell() 
    : m_value("")
    , m_color(Color::White)
{}

Cell::Cell(const std::string& value, const Color& color) 
    : m_value(value)
    , m_color(color)
{}

std::string Cell::get_value() const {
    return m_value;
}

void Cell::set_value(const std::string& value) {
    m_value = value;
}

Color Cell::get_color() const {
    return m_color;
}

void Cell::set_color(const Color& color) {
    m_color = color;
}

void Cell::reset() {
    m_value = "";
    m_color = Color::White;
}

int Cell::to_int() {
    if (!is_valid_number()) {
        throw std::invalid_argument("The value can't be converted to int.");
    }
    auto pos = m_value.find('.');
    if (pos != std::string::npos) {
        return stoi(m_value.substr(0, pos));
    }
    return stoi(m_value);
}

double Cell::to_double() {
    if (!is_valid_number()) {
        throw std::invalid_argument("The value can't be converted to int.");
    }
    return std::stod(m_value);
}

Date Cell::to_date() {
    if (!is_valid_date()) {
        throw std::invalid_argument("Invalid date.");
    }
    std::vector<std::string>* parsed = parse(m_value);
    Year year(stoi((*parsed)[0]));
    Month month(stoi((*parsed)[1]));
    Day day(stoi((*parsed)[2]));
    Date date(year, month, day);
    return date;
}

bool Cell::is_valid_number() {
    bool dot_seen = false;
    bool number_seen = false;
    for (int i = 0; i < m_value.size(); ++i) {
        if (m_value[i] >= '0' && m_value[i] <= '9') {
            number_seen = true;
        }
        else if (m_value[i] == '.') {
            if (dot_seen || !number_seen) {
                return false;
            }
            dot_seen = true;
        }
        else {
            return false;
        }
    }
    return true;
}

bool Cell::is_valid_date() {
    std::tm t = {};
    if (strptime(m_value.c_str(), "%Y-%m-%d", &t) != nullptr) {
        return true;
    }
    return false;
}

std::vector<std::string>* Cell::parse(const std::string& line) {
	std::vector<std::string>* result = new std::vector<std::string>();
	unsigned start = 0;
	for (unsigned end = 0; end < line.size() + 1; ++end) {
		if ((end != line.size() - 1 && line[end] == '-') || line[end] == '\0') {
			std::string current = line.substr(start, end - start);
			result->push_back(current);
			start = end + 1;
		}
		else if (end == line.size() - 1 && line[end] == '-') {
			continue;
		}
	}
	return result;
}