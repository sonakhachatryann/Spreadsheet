#ifndef CELL_H
#define CELL_H

#include <string>
#include "color.h"
#include "date.h"

class Cell {
public:
    Cell();
    Cell(const std::string&, const Color&);

    Cell& operator=(const Cell&);

    std::string get_value() const;
    void set_value(const std::string&);
    Color get_color() const;
    void set_color(const Color& color);
    void reset();
    int to_int();
    double to_double();
    Date to_date();

private:
    bool is_valid_number();
    bool is_valid_date();
    std::vector<std::string>* parse(const std::string&);

private:
    std::string m_value;
    Color m_color;
};

#endif //CELL_H