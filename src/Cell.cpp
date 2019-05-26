#include "Cell.h"
#include <iostream>

Cell::Cell(){}

Cell::Cell(int value){
	this->value  = value;
	this->is_tip = (value == 0);
}

bool Cell::get_is_tip(){
	return is_tip;
}

void Cell::set_value(int value){
	this->value = value;
}

int Cell::get_value(){
	return value;
}

void Cell::create_edge(Cell* adjacent){
	adjacent_to.push_back(adjacent);
}

bool Cell::is_adjacent_to(Cell* test){
	for(int i = 0;i < adjacent_to.size();i++){
		if(test == adjacent_to.at(i))return true;
	}
	return false;
}

void Cell::say_adjacents(){
	for(int i = 0;i < adjacent_to.size();i++){
		std::cout<<adjacent_to.at(i)->get_value()<<" ";
	}
}

bool Cell::is_legal(){
	for(int i = 0;i < adjacent_to.size();i++){
		int adjacent_value = adjacent_to.at(i)->get_value();
		if(adjacent_value == value && adjacent_value!= 0 )return false;
	}
	return true;
}