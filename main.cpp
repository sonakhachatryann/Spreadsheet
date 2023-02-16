#include <iostream>

#include "tester.h"
#include "spreadsheet.h"

int main() {
    try{
        Tester test;
        test.cell_values();
        test.date();
        test.cell_operations();
        test.row_col_operations();
        test.test_insert();
        
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}