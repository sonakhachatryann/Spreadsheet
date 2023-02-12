#ifndef DATE_CELL_H
#define DATE_CELL_H

#include "cell.h"

class DateCell : public Cell {
public:
    DateCell(const Date&, const Color&);

    virtual void write(std::ofstream&) const override;
    virtual std::string get_string_value() const override;
    virtual void reset() override;

    Date get_value() const;
    void set_value(const Date&);

private:
    Date m_value;
};

#endif //DATE_CELL_H