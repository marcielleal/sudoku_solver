#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

#include "sudoku.h"
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

void Manager::say_answers(){
	for(int i = 0; i<answer_list.size(); i++){
		std::cout<<answer_list[i]<<std::endl;
	}
}