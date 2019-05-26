#ifndef SUDOKUH
#define SUDOKUH

#include <string>
#include "Cell.h"

class Sudoku{
private:
	Cell*** cell_matrix;

public:
	Sudoku();
	Sudoku(std::string);

	void initialize_values(std::string);
	void alocate_cell_matrix();
	void set_adjacencies();
	void set_cell_rules(Cell*,int,int);
	void show_sudoku();
	Cell* index_to_cell(int);
	bool solve();
};

#endif