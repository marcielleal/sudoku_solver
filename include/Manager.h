#ifndef MANAGERH
#define MANAGERH

#include <string>
#include <vector>

class Manager{
private:
	std::vector< std::string > puzzle_list;
	std::vector< std::string > answer_list;

	std::vector< int > times_list;

public:
	Manager();
	void init_lists();
	void say_answers();

};

#endif