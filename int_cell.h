#ifndef INT_CELL_H
#define INT_CELL_H

#include <iostream>
#include "cell.h"

class IntCell : public Cell {
public:
    IntCell();
    IntCell(int, const Color&);

    virtual void write(std::ofstream&) const override;
    virtual std::string get_string_value() const override;
    virtual void reset() override;

    int get_value() const;
    void set_value(int);

private:
    int m_value;
};

#endif //INT_CELL_H