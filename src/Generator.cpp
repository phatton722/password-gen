/* Generator.cpp */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../include/Generator.h"

/* Generates a new password for the user with:
   1. Length between 8-20 characters
   2. Uses ASCII characters from 33-126 */
std::string Generator::newPassword(int length){

	srand(time(nullptr));

	char* ascii_char = new char[length+1];
	*ascii_char = 0;

	for(int i = 0; i < length; i++){
		*(ascii_char+i) = (int)(unsigned char)((rand() % 94) + 33);
	} 

	std::string temp_str(reinterpret_cast<char*>(ascii_char), length);

	delete[] ascii_char;
	return temp_str;
}


/* Takes current password from the user and then generates a 
   password of the same length */
void Generator::modPassword(std::string& password){

	srand(time(nullptr));
	
	int plus_or_minus = 0;
	int shift_val = 0;

	for(int i = 0; i < password.length(); i++){
		plus_or_minus = rand() % 2;
		shift_val = rand() % 95;

		if(plus_or_minus == 0){
			password.at(i) = 
			  (unsigned char)((unsigned)33 + ( 
			    ((unsigned char)password.at(i) + (unsigned)shift_val) % 94));
		}

		if(plus_or_minus == 1){
			password.at(i) = 
			  (unsigned char)((unsigned)33 + ( 
				((unsigned char)password.at(i) - (unsigned)shift_val) % 94));
		}

	}
}

/* Prints password */
void Generator::printPassword(std::string& password){
	std::cout << "New password: " << "-->" << password << "<--" << std::endl;
}
