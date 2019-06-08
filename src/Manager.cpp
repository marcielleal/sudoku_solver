#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

#include "Sudoku.h"
#include "Manager.h"

Manager::Manager(){}

void Manager::init_lists(){
	std::string line;
	std::string puzzle;
	std::string answer;

	std::ifstream file ("/home/eric/Faculdade/Grafos/input/sudoku_input/sudoku.csv");
	
	while (file && getline(file, line)){
		//if (line.length() == 0)continue;

		puzzle = line.substr(0,81);
		answer = line.substr(82,81);

		puzzle_list.push_back(puzzle);
		answer_list.push_back(answer);

	}

}

void Manager::time_test_list(){

	auto begin = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();


	for(int i = 0; i < puzzle_list.size() ; i++){
		
		std::cout<< "resolvendo " << i << std::endl;

		Sudoku sudoku( puzzle_list.at(i) );

		//inicializa a contagem em milissegundos para resolver o sudoku
		begin = std::chrono::high_resolution_clock::now();

		sudoku.solve();

		end = std::chrono::high_resolution_clock::now();    
    	dur = end - begin;
    	ms = std::chrono::duration_cast<std::chrono::microseconds >(dur).count();

    	times_list.push_back( (int)ms );
	}

}

void Manager::export_time_csv(){

	std::ofstream file ("./output/time_record.csv");

	for(int i = 0; i < times_list.size(); i++){
		file << times_list.at(i)<< std::endl;
	}
}

void Manager::solve_random(){
	srand (time(NULL));
	int selected = rand() % puzzle_list.size();

	Sudoku sudoku(puzzle_list.at(selected));
	sudoku.show_sudoku();
	sudoku.solve();
	sudoku.print_answer();

}

void Manager::display(){
	init_lists();

	int option;

	std::cin

}