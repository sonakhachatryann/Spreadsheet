#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "cell.h"

class Spreadsheet {
public:
    Spreadsheet() = delete;
    Spreadsheet(Cell**, int, int);
    ~Spreadsheet();

    int get_row() const;
    int get_col() const;
    void set_row(int);
    void set_col(int);
    void set_cell_at(int, int, const Cell&);
    void set_cell_at(int, int, const std::string&);
    Cell get_cell_at(int, int);
    void add_row(int);
    void remove_row(int);
    void add_column(int);
    void remove_column(int);
    void swap_rows(int, int);
    void swap_columns(int, int);

private:
    bool check_indexes(int, int) const;
    void allocate_and_initialize(Cell**);
    void deallocate();

private:
    Cell** m_cells;
    int m_row;
    int m_col;
};

#endif //SPREADSHEET_H