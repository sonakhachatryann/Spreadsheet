#ifndef STRING_CELL_H
#define STRING_CELL_H

#include "cell.h"

class StringCell : public Cell {
public:
    StringCell();
    StringCell(const std::string&, const Color&);

    virtual void write(std::ofstream&) const override;
    virtual std::string get_string_value() const override;
    virtual void reset() override;

    std::string get_value() const;
    void set_value(const std::string&);

private:
    std::string m_value;
};

#endif //STRING_CELL_H