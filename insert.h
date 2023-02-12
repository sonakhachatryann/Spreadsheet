#ifndef INSERT_H
#define INSERT_H

#include "fstream"
#include "spreadsheet.h"

class Insert {
public:
    Insert(const std::string&, Spreadsheet*);
    void write();

private:
    std::string filename_;
    Spreadsheet* spreadsheet_;
};

#endif //INSERT_H