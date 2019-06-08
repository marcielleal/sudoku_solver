#include <iostream>
#include <chrono>

#include "Cell.h"
#include "Sudoku.h"
#include "Manager.h"


int main(){

	auto begin = std::chrono::high_resolution_clock::now();    

	/*
	Sudoku sudoku("900000400500219000023080070004700298001000003090300004052007060070004980030162500");
	sudoku.show_sudoku();
	sudoku.solve();
	sudoku.print_answer();
	//std::cout<<cell.get_value()<<std::endl;
	*/
	Manager manager;

	manager.init_lists();
	//manager.say_answers();

	auto end = std::chrono::high_resolution_clock::now();    
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << ms << std::endl;
}