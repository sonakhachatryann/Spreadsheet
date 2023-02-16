#include "spreadsheet.h"
#include <algorithm>

Spreadsheet::Spreadsheet(int rows, int cols) {
    allocate_and_initialize(rows, cols);
}

Spreadsheet::~Spreadsheet() {
    deallocate();
}

int Spreadsheet::get_row() const {
    return m_cells.rbegin()->first + 1;
}

int Spreadsheet::get_col() const {
    int num_cols = 0;
    for (auto& row : m_cells) {
        num_cols = std::max(num_cols, row.second.rbegin()->first + 1);
    }
    return num_cols; 
}

void Spreadsheet::set_cell_at(int i, int j, Cell* cell) {
    if (!check_indexes(i, j)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    m_cells[i][j] = cell;
}

Cell* Spreadsheet::get_cell_at(int i, int j) {
    if (!check_indexes(i, j)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    return m_cells[i][j];
}

void Spreadsheet::add_row(int row) {
    if (row < -1 || row >= get_row()) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    std::map<int, std::map<int, Cell*>> tmp_map;
    for (int i = 0; i <= row; ++i) {
        for (int j = 0; j < get_col(); ++j) {
            tmp_map[i][j] = m_cells[i][j];
        }
    }
    for (int j = 0; j < get_col(); ++j) {
        tmp_map[row + 1][j] = nullptr;
    }
    for (int i = row + 2; i <= get_row(); ++i) {
        for (int j = 0; j < get_col(); ++j) {
            tmp_map[i][j] = m_cells[i - 1][j];
        }
    }
    m_cells = tmp_map;
}

void Spreadsheet::remove_row(int row) {
    if (row < 0 || row >= get_row()) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    std::map<int, std::map<int, Cell*>> tmp_map;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < get_col(); ++j) {
            tmp_map[i][j] = m_cells[i][j];
        }
    }
    for (int i = row; i < get_row() - 1; ++i) {
        for (int j = 0; j < get_col(); ++j) {
            tmp_map[i][j] = m_cells[i + 1][j];
        }
    }
    m_cells = tmp_map;
}

void Spreadsheet::add_column(int col) {
    if (col < -1 || col >= get_col()) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    std::map<int, std::map<int, Cell*>> tmp_map;
    for (int i = 0; i < get_row(); ++i) {
        for (int j = 0; j <= col; ++j) {
            tmp_map[i][j] = m_cells[i][j];
        }
    }
    for (int i = 0; i < get_row(); ++i) {
        tmp_map[i][col + 1] = nullptr;
    }
    for (int i = 0; i < get_row(); ++i) {
        for (int j = col + 2; j <= get_col(); ++j) {
            tmp_map[i][j] = m_cells[i][j - 1];
        }
    }
    m_cells = tmp_map;	
}

void Spreadsheet::remove_column(int col) {
    if (col < 0 || col >= get_col()) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    std::map<int, std::map<int, Cell*>> tmp_map;
    for (int i = 0; i < get_row(); ++i) {
        for (int j = 0; j < col; ++j) {
            tmp_map[i][j] = m_cells[i][j];
        }
    }
    for (int i = 0; i < get_row(); ++i) {
        for (int j = col; j < get_col() - 1; ++j) {
            tmp_map[i][j] = m_cells[i][j + 1];
        }
    }
    m_cells = tmp_map;	
}

void Spreadsheet::swap_rows(int r1, int r2) {
    if (!check_indexes(r1, r2)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    if (r1 == r2) {
        return;
    }
    auto it1 = m_cells.find(r1);
    auto it2 = m_cells.find(r2);
    if (it1 != m_cells.end() && it2 != m_cells.end()) {
        Cell* tmp;
        for (auto iter1 = it1->second.begin(), iter2 = it2->second.begin(); 
            iter1 != it1->second.end() && iter2 != it2->second.end(); ++iter1, ++iter2) {
            tmp = iter1->second;
            iter1->second = iter2->second;
            iter2->second = tmp;
        }
    }
    else {
        throw std::invalid_argument("Invalid value for rows.");
    }
}

void Spreadsheet::swap_columns(int c1, int c2) {
    if (!check_indexes(c1, c2)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    if (c1 == c2) {
        return;
    }
    Cell* tmp;
    for (auto it = m_cells.begin(); it != m_cells.end(); ++it) {
        auto it1 = it->second.find(c1);
        auto it2 = it->second.find(c2);
        if (it1 != it->second.end() && it2 != it->second.end()) {
            tmp = it1->second;
            it1->second = it2->second;
            it2->second = tmp;
        }
    }
}

void Spreadsheet::insert(const std::string& filename) {
    std::ofstream out;
    out.open(filename, std::ofstream::app);
    if (!out.is_open()) {
        throw std::runtime_error("Can not open the file!");
    }
    for (int i = 0; i < get_row(); ++i) {
        for (int j = 0; j < get_col(); ++j) {
            out << "row: " << i << " " << "col: " << j << " ";
            get_cell_at(i, j)->write(out);
        }
    }
    out.close();
}

bool Spreadsheet::check_indexes(int i, int j) const {
    if (i < 0 || i >= get_row() || j < 0 || j >= get_col()) {
		return false;
	}
    return true;
}

void Spreadsheet::allocate_and_initialize(int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m_cells[i][j] = nullptr;
        }
    }
}

void Spreadsheet::deallocate() {
    for (auto& row : m_cells) {
        for (auto& cell : row.second) {
            delete cell.second;
        }
    }
}