#include <iostream>

#include "tester.h"
#include "spreadsheet.h"

void Tester::cell_values() {
    Cell c1;
    c1.set_color(Color::Blue);
    c1.set_value("45.145");
    if (c1.to_int() == 45) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    Cell c2("Hello world", Color::Pink);
    Cell c3("3.14", Color::Yellow);
    if (c3.to_double() + 1 == 3.14 + 1) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    Cell c4("2010-09-23", Color::Blue);
    if (c4.to_date().get_day()._day == 23) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Tester::date() {
    Day d(28);
    Month m(02);
    Year y(2021);
    Date date(y, m, d);
    if (date.get_day()._day == 28) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (date.get_month()._month == 2) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (date.get_year()._year == 2021) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
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
    if (sh.get_cell_at(0, 1).get_value() == "2") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(1, 1).get_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.swap_rows(0, 1);
    if (sh.get_cell_at(0, 1).get_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(1, 1).get_value() == "2") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.swap_columns(0, 1);
    if (sh.get_cell_at(0, 1).get_value() == "3") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(1, 1).get_value() == "1") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Tester::row_col_operations() {
    int n = 2;
    int m = 2;
    Cell** data = new Cell*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new Cell[m] {};
    }
    Cell c1("1", Color::Blue);
    Cell c2("2", Color::Green);
    Cell c3("3", Color::Pink);
    Spreadsheet sh(data, n, m);
    sh.set_cell_at(0, 0, c1);
    sh.set_cell_at(0, 1, c2);
    sh.set_cell_at(1, 0, c3);
    sh.set_cell_at(1, 1, "4");
    sh.get_cell_at(1, 1).set_color(Color::White);
    sh.add_row(0);
    if (sh.get_cell_at(1,0).get_value() == "") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(0,0).get_value() == "1") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(2,1).get_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.add_column(0);
    if (sh.get_cell_at(1,1).get_value() == "") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(2,2).get_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.remove_row(1);
    if (sh.get_cell_at(1,1).get_value() == "") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(1,2).get_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.remove_column(1);
    if (sh.get_cell_at(1,1).get_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    if (sh.get_cell_at(0,1).get_value() == "2") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}