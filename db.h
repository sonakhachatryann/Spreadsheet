#ifndef DB_H
#define DB_H

#include "table.h"

#include <vector>
#include <tuple>

template<typename... types>
class DB : public Table {
    DB();
    ~DB();

    void add_row(int) override;
    void remove_row(int) override;
    void add_column(int) override;
    void remove_column(int) override;
    void swap_rows(int, int) override;
    void swap_columns(int, int) override;
    void insert(const std::string&) override;

private:
    std::vector<std::tuple<types...>> data;
};

#endif //DB_H