#ifndef SUDOKUH
#define SUDOKUH

#include <string>
#include <vector>
#include "Cell.h"

class Sudoku{
private:
	Cell*** cell_matrix;
	
	std::vector<int> answer;
	bool test_cell(int);
	Cell* index_to_cell(int);
	void initialize_values(std::string);
	void alocate_cell_matrix();
	void set_adjacencies();
	void set_cell_rules(Cell*,int,int);

public:
	Sudoku();
	Sudoku(std::string);

	~Sudoku();

	void show_sudoku();	
	void print_answer();

	std::string get_answer();

	void solve();

};

#endif