#include <iostream>

#include "tester.h"

void Tester::cell_values() {
    IntCell* c1 = new IntCell();
    c1->set_color(Color::Blue);
    c1->set_value(45.415);
    if (c1->get_value() == 45) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    StringCell* c2 = new StringCell();
    c2->set_color(Color::Pink);
    c2->set_value("Hello World");
    DoubleCell* c3 = new DoubleCell();
    c3->set_color(Color::Yellow);
    c3->set_value(3.14);
    if (c3->get_value() + 1 == 3.14 + 1) {
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
    IntCell* c1 = new IntCell(1, Color::Blue);
    IntCell* c2 = new IntCell(2, Color::Green);
    IntCell* c3 = new IntCell(3, Color::Pink);
    IntCell* c4 = new IntCell(4, Color::Pink);
    Spreadsheet sh(n, m);
    sh.set_cell_at(0, 0, c1);
    sh.set_cell_at(0, 1, c2);
    sh.set_cell_at(1, 0, c3);
    sh.set_cell_at(1, 1, c4);
    IntCell* tmp1 = dynamic_cast<IntCell*>(sh.get_cell_at(0, 1));
    if (tmp1->get_value() == 2) { 
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    IntCell* tmp2 = dynamic_cast<IntCell*>(sh.get_cell_at(1, 1));
    if (tmp2->get_value() == 4) { 
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.swap_rows(0, 1);
    IntCell* tmp3 = dynamic_cast<IntCell*>(sh.get_cell_at(0, 1));
    if (tmp3->get_value() == 4) { 
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    IntCell* tmp4 = dynamic_cast<IntCell*>(sh.get_cell_at(1, 1));
    if (tmp4->get_value() == 2) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.swap_columns(0, 1);
    IntCell* tmp5 = dynamic_cast<IntCell*>(sh.get_cell_at(0, 1));
    if (tmp5->get_value() == 3) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    IntCell* tmp6 = dynamic_cast<IntCell*>(sh.get_cell_at(1, 1));
    if (tmp6->get_value() == 1) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Tester::row_col_operations() {
    int n = 2;
    int m = 2;
    StringCell* c1 = new StringCell("1", Color::White);
    StringCell* c2 = new StringCell("2", Color::Blue);
    StringCell* c3 = new StringCell("3", Color::Green);
    StringCell* c4 = new StringCell("4", Color::Pink);
    Spreadsheet sh(n, m);
    sh.set_cell_at(0, 0, c1);
    sh.set_cell_at(0, 1, c2);
    sh.set_cell_at(1, 0, c3);
    sh.set_cell_at(1, 1, c4);
    sh.add_row(0);
    StringCell* c5 = new StringCell("5", Color::White);
    StringCell* c6 = new StringCell("6", Color::Blue);
    sh.set_cell_at(1, 0, c5);
    sh.set_cell_at(1, 1, c6);  
    StringCell* tmp1 = dynamic_cast<StringCell*>(sh.get_cell_at(0, 0));
    if (tmp1->get_string_value() == "1") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    StringCell* tmp2 = dynamic_cast<StringCell*>(sh.get_cell_at(1, 0));
    if (tmp2->get_string_value() == "5") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    StringCell* tmp3 = dynamic_cast<StringCell*>(sh.get_cell_at(2, 1));
    if (tmp3->get_string_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.add_column(0);
    StringCell* c7 = new StringCell("7", Color::White);
    StringCell* c8 = new StringCell("8", Color::Blue);
    StringCell* c9 = new StringCell("9", Color::White);
    sh.set_cell_at(0, 1, c7);
    sh.set_cell_at(1, 1, c8);
    sh.set_cell_at(2, 1, c9);
    StringCell* tmp4 = dynamic_cast<StringCell*>(sh.get_cell_at(1, 1));
    if (tmp4->get_string_value() == "8") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    StringCell* tmp5 = dynamic_cast<StringCell*>(sh.get_cell_at(2, 2));
    if (tmp5->get_string_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    
    sh.remove_row(1);
    StringCell* tmp6 = dynamic_cast<StringCell*>(sh.get_cell_at(1, 1));
    if (tmp6->get_string_value() == "9") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    StringCell* tmp7 = dynamic_cast<StringCell*>(sh.get_cell_at(1, 2));
    if (tmp7->get_string_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    sh.remove_column(1);
    StringCell* tmp8 = dynamic_cast<StringCell*>(sh.get_cell_at(1, 1));
    if (tmp8->get_string_value() == "4") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    StringCell* tmp9 = dynamic_cast<StringCell*>(sh.get_cell_at(0, 0));
    if (tmp9->get_string_value() == "1") {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

void Tester::test_insert() {
    int n = 2;
    int m = 2;
    Year y(2023);
    Month mn(2);
    Day d(12);
    Date date(y, mn, d);
    IntCell* c1 = new IntCell(1, Color::Blue);
    DoubleCell* c2 = new DoubleCell(2.3, Color::Green);
    StringCell* c3 = new StringCell("hello world", Color::Pink);
    DateCell* c4 = new DateCell(date, Color::Pink);
    Spreadsheet* sh = new Spreadsheet(n, m);
    sh->set_cell_at(0, 0, c1);
    sh->set_cell_at(0, 1, c2);
    sh->set_cell_at(1, 0, c3);
    sh->set_cell_at(1, 1, c4);
    std::string filename = "cells.txt";
    sh->insert(filename);
}