#ifndef CELL_H
#define CELL_H

#include <string>
#include <fstream>
#include "color.h"
#include "date.h"

class Cell {
public:
    Cell();
    Cell(const Color&);
    virtual void write(std::ofstream&) const = 0;
    virtual std::string get_string_value() const = 0;
    virtual void reset();
    std::string color_to_string() const;
    Color get_color() const;
    void set_color(const Color& color);

protected:
    Color m_color;
};

#endif //CELL_H