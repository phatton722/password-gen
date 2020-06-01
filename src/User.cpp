/* User.cpp */

#include <iostream>
#include <string>
#include <limits>
#include "../include/User.h"
#include "../include/Clear.h"

/* Asks user if they want to create a new password
   or to modify an existing one */
void User::getUserDecision(std::string& answer){

	Clear clr;
	bool done = 0;

	std::cout << std::endl << std::endl;
	std::cout << "What would you like to do?" << std::endl
			  << "1. Create a new random password " << std::endl
			  << "2. Modify a current password " << std::endl
			  << "3. Create a new password with a keyword " << std::endl
			  << "Please enter your response [1/2/3]: ";

	do{
		std::cin >> answer;

		if(answer == "1" || answer == "2" || answer == "3"){
			done = 1;
		}
		else{
			clr.errorMessage();
			clr.resetBuffer();
			answer = "";
		}

	} while(done == 0);
}

void User::getNewLength(int& length){

	Clear clr;
	bool done = 0;

	std::cout << "How many characters would you like the password to be? "
			  << "Must be 6-20 characters: ";

	do{
		std::cin >> length;

		if(std::cin.fail()){
			clr.errorMessage();
			clr.resetBuffer();
			length = 0;
			continue;
		}

		else if(length < 6 || length > 20){
			clr.errorMessage();
			clr.resetBuffer();
			length = 0;
		}	
		else{
			done = 1;
		}

	} while(done == 0);
}

void User::getUserPassword(std::string& password){
	
	Clear clr;
	bool done = 0;
	
	std::cout << "Please enter the password you would like to change. "
			  << "Must be 6-20 characters long: ";

	do{
		std::cin >> password;
		std::cout << password;

		if(password.length() > 20 || password.length() < 6){ 
			clr.errorMessage();
			clr.resetBuffer();

			password.clear();
		}
		else{
			done = 1;
		}

	} while(done == 0 && password.empty());
}
