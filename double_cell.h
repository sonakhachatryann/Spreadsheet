#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

#include "cell.h"

class DoubleCell : public Cell {
public:
    DoubleCell();
    DoubleCell(double, const Color&);
    virtual ~DoubleCell() = default;

    virtual void write(std::ofstream&) const override;
    virtual std::string get_string_value() const override;
    virtual void reset() override;

    double get_value() const;
    void set_value(double);

private:
    double m_value;
};

#endif //DOUBLE_CELL_H