#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <map>
#include "cell.h"
#include "table.h"

class Spreadsheet : Table {
public:
    Spreadsheet() = delete;
    Spreadsheet(int, int);
    ~Spreadsheet();

    int get_row() const;
    int get_col() const;
    void set_cell_at(int, int, Cell*);
    Cell* get_cell_at(int, int);
    void add_row(int) override;
    void remove_row(int) override;
    void add_column(int) override;
    void remove_column(int) override;
    void swap_rows(int, int) override;
    void swap_columns(int, int) override;
    void insert(const std::string&) override;

private:
    bool check_indexes(int, int) const;
    void allocate_and_initialize(int, int);
    void deallocate();

private:
    std::map<int, std::map<int, Cell*>> m_cells;
};

#endif //SPREADSHEET_H