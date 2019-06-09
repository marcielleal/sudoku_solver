#ifndef MANAGERH
#define MANAGERH

#include <string>
#include <vector>

class Manager{
private:
	std::vector< std::string > puzzle_list;
	std::vector< std::string > answer_list;

	std::vector< int > times_list;

	void clear_screen();

public:
	Manager();
	
	void init_lists();

	void time_test_list();
	void answer_test_list();

	void export_time_csv();

	void solve_random();

	void display();
};

#endif