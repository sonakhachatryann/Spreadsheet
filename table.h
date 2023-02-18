#ifndef TABLE_H
#define TABLE_H

#include <string>

class Table {
public:
    virtual int get_row() const = 0;
    virtual int get_col() const = 0;
    virtual void add_row(int) = 0;
    virtual void remove_row(int) = 0;
    virtual void add_column(int) = 0;
    virtual void remove_column(int) = 0;
    virtual void swap_rows(int, int) = 0;
    virtual void swap_columns(int, int) = 0;
    virtual void insert(const std::string&) = 0;
};

#endif //TABLE_H