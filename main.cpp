#include <iostream>

#include "tester.h"
#include "spreadsheet.h"
#include "insert.h"

int main() {
    try{
        Tester test;
        test.cell_values();
        test.date();
        test.cell_operations();
        test.row_col_operations();
        
        //writing to a file
        /*int n = 2;
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
        Insert insert(filename, sh);
        insert.write();*/
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}