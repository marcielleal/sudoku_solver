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

	auto begin = std::chrono::high_resolution_clock::now();

	sudoku.solve();

	auto end = std::chrono::high_resolution_clock::now();    
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds >(dur).count();

	sudoku.print_answer();



}

void Manager::display(){
	clear_screen();
	std::cout << "Loading..." << std::endl;
	clear_screen();

	init_lists();


	int option;


	do{
		std::cout <<
		"1 - Solve list and report time\n"<<
		"2 - Solve a random puzzle from the list\n"<<
		"3 - Exit\n";

		std::cin >> option;

		switch(option){
			case 1:
				time_test_list();
				export_time_csv();
				break;
			case 2:
				solve_random();
				break;
			default:
				return;
		}

		std::cout << "Press any key to continue" << std::endl;
		std::cin.ignore();
		std::getchar();
		clear_screen();


	}while(true);

}

void Manager::clear_screen(){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
}