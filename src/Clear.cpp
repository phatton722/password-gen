/* Clear.cpp */

#include <iostream>
#include <limits>
#include "../include/Clear.h"

typedef std::numeric_limits<std::streamsize> input;

void Clear::errorMessage(void){
	std::cout << "Invalid input! Please try again: ";
}

void Clear::resetBuffer(void){
	std::cin.clear();
	std::cin.ignore(input::max(), '\n');
	std::cin.sync();
}
