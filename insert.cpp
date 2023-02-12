#include "insert.h"

Insert::Insert(const std::string& filename, Spreadsheet* spreadsheet)  
    : filename_(filename)
    , spreadsheet_(spreadsheet)
{}

void Insert::write() {
    std::ofstream out(filename_);
    for (int i = 0; i < spreadsheet_->get_row(); ++i) {
        for (int j = 0; j < spreadsheet_->get_col(); ++j) {
            out << "row: " << i << " " << "col: " << j << " ";
            spreadsheet_->get_cell_at(i, j)->write(out);
        }
    }
    out.close();
}