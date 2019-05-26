#ifndef CELLH
#define CELLH

#include <vector>

class Cell{
private:
	int value;
	bool is_tip;
	std::vector<Cell*> adjacent_to;
public:
	Cell();
	Cell(int);
	bool get_is_tip();
	int  get_value();
	void set_value(int);
	void create_edge(Cell*);
	bool is_adjacent_to(Cell*);
	void say_adjacents();
};

#endif