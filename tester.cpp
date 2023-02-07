#include <iostream>

#include "tester.h"
#include "spreadsheet.h"

void Tester::cell_values() {
    Cell c1;
    c1.set_color(Color::Blue);
    c1.set_value("45.145");
    std::cout << c1.to_int() << std::endl;
    Cell c2("Hello world", Color::Pink);
    std::cout << c2.to_int() << std::endl;
    Cell c3("3.14", Color::Yellow);
    std::cout << c3.to_double() + 1 << std::endl;
    Cell c4("2010-09-23", Color::Blue);
    std::cout << c4.to_date().get_day()._day << std::endl;
}

void Tester::date() {
   Day d(28);
   Month m(02);
   Year y(2021);
   Date(y, m, d);
}

void Tester::cell_operations() {
    int n = 2;
    int m = 2;
    Cell** data = new Cell*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new Cell[m];
    }
    Cell c1("1", Color::Blue);
    Cell c2("2", Color::Green);
    Cell c3("3", Color::Pink);
    Spreadsheet sh(data, n, m);
    sh.set_cell_at(0, 0, c1);
    sh.set_cell_at(0, 1, c2);
    sh.set_cell_at(1, 0, c3);
    sh.set_cell_at(1, 1, "4");
    std::cout << sh.get_cell_at(0, 1).get_value() << std::endl;
    std::cout << sh.get_cell_at(1, 1).get_value() << std::endl;
    sh.swap_rows(0, 1);
    std::cout << sh.get_cell_at(0, 1).get_value() << std::endl;
    std::cout << sh.get_cell_at(1, 1).get_value() << std::endl;
    sh.swap_columns(1, 1);
    std::cout << sh.get_cell_at(0, 1).get_value() << std::endl;
    std::cout << sh.get_cell_at(1, 1).get_value() << std::endl;
}

void Tester::row_col_operations() {
    int n = 2;
    int m = 2;
    Cell** data = new Cell*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new Cell[m];
    }
    Cell c1("1", Color::Blue);
    Cell c2("2", Color::Green);
    Cell c3("3", Color::Pink);
    Spreadsheet sh(data, n, m);
    sh.set_cell_at(0, 0, c1);
    sh.set_cell_at(0, 1, c2);
    sh.set_cell_at(1, 0, c3);
    sh.set_cell_at(1, 1, "4");
    sh.add_row(0);
    sh.add_column(0);
    sh.remove_row(1);
    sh.remove_column(1);
}