#include "spreadsheet.h"

Spreadsheet::Spreadsheet(Cell** cell, int row, int col) {
    set_row(row);
    set_col(col);
    allocate_and_initialize(cell);
}

Spreadsheet::~Spreadsheet() {
    deallocate();
}

int Spreadsheet::get_row() const {
    return m_row;
}

int Spreadsheet::get_col() const {
    return m_col;
}

void Spreadsheet::set_row(int row) {
    if (row < 0) {
        throw std::invalid_argument("Invalid value for row.");
    }
    m_row = row;
}

void Spreadsheet::set_col(int col) {
    if (col < 0) {
        throw std::invalid_argument("Invalid value for row.");
    }
    m_col = col;
}

void Spreadsheet::set_cell_at(int i, int j, const Cell& cell) {
    if (!check_indexes(i, j)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    m_cells[i][j] = cell;
}

void Spreadsheet::set_cell_at(int i, int j, const std::string& value) {
    if (!check_indexes(i, j)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    m_cells[i][j].set_value(value);
}

Cell Spreadsheet::get_cell_at(int i, int j) {
    if (!check_indexes(i, j)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    return m_cells[i][j];
}

void Spreadsheet::add_row(int row) {
    if (row < -1 || row >= m_row) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    Cell** cells = new Cell*[m_row + 1]{};
    for (int i = 0; i < m_row + 1; ++i) {
        cells[i] = new Cell[m_col] {};
    }
    for (int i = 0; i <= row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
    cells[row + 1] = new Cell[m_col] {};
    for (int i = row + 2; i <= m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i - 1][j];
		}
	}
    deallocate();
    m_cells = cells;
    ++m_row;
}

void Spreadsheet::remove_row(int row) {
    if (row < 0 || row >= m_row) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    Cell** cells = new Cell*[m_row - 1]{};
    for (int i = 0; i < m_row - 1; ++i) {
        cells[i] = new Cell[m_col] {};
    }
    for (int i = 0; i < row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
    for (int i = row + 1; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			cells[i - 1][j] = m_cells[i][j];
		}
	}
    deallocate();
    m_cells = cells;
    --m_row;
}

void Spreadsheet::add_column(int col) {
    if (col < -1 || col >= m_col) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    Cell** cells = new Cell*[m_row]{};
    for (int i = 0; i < m_row; ++i) {
        cells[i] = new Cell[m_col + 1] {};
    }
    for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j <= col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
    for (int i = 0; i < m_row; ++i) {
		for (int j = col + 2; j <= m_col; ++j) {
			cells[i][j] = m_cells[i][j - 1];
		}
	}
    deallocate();
    m_cells = cells;
    ++m_col;
}

void Spreadsheet::remove_column(int col) {
    if (col < 0 || col >= m_col) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    Cell** cells = new Cell*[m_row]{};
    for (int i = 0; i < m_row; ++i) {
        cells[i] = new Cell[m_col - 1] {};
    }
    for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < col; ++j) {
			cells[i][j] = m_cells[i][j];
		}
	}
    for (int i = 0; i < m_row; ++i) {
		for (int j = col + 1; j < m_col; ++j) {
			cells[i][j - 1] = m_cells[i][j];
		}
	}
    deallocate();
    m_cells = cells;
    --m_col;
}

void Spreadsheet::swap_rows(int i, int j) {
    if (!check_indexes(i, j)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    if (i == j) {
        return;
    }
    Cell* tmp = m_cells[i];
	m_cells[i] = m_cells[j];
	m_cells[j] = tmp;
}

void Spreadsheet::swap_columns(int n, int m) {
    if (!check_indexes(n, m)) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    if (n == m) {
        return;
    }
    for (int i = 0; i < m_row; ++i) {
		Cell tmp = m_cells[i][n];
		m_cells[i][n] = m_cells[i][m];
		m_cells[i][m] = tmp;
	}
}

bool Spreadsheet::check_indexes(int i, int j) const {
    if (i < 0 || i >= m_row || j < 0 || j >= m_col) {
		return false;
	}
    return true;
}

void Spreadsheet::allocate_and_initialize(Cell** cell) {
    if (cell) {
        m_cells = new Cell*[m_row]{};
        for (int i = 0; i < m_row; ++i) {
            m_cells[i] = new Cell[m_col] {};
        }   
        for (int i = 0; i < m_row; ++i) {
		    for (int j = 0; j < m_col; ++j) {
			    m_cells[i][j] = cell[i][j];
		    }
	    }
    }
}

void Spreadsheet::deallocate() {
    if (m_cells) {
        for (int i = 0; i < m_row; ++i) {
		    delete[] m_cells[i];
	    }
	    delete[] m_cells;
    }
}