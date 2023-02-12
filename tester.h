#ifndef TESTER_H
#define TESTER_H

#include "spreadsheet.h"
#include "int_cell.h"
#include "double_cell.h"
#include "date_cell.h"
#include "string_cell.h"

class Tester {
public:
    void cell_values();
    void date();
    void cell_operations();
    void row_col_operations();
};

#endif //TESTER_H