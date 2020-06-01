/* main.cpp */

#include <iostream>
#include <string>
#include "../include/User.h"
#include "../include/Generator.h"
#include "../include/Modify.h"
#include "../include/Keyword.h"

int main(void){

	User user;
	Generator generator;
	Modify modify;
	Keyword keyword;

	char userInput = 0;
	int length = 0;

	std::string userInputStr("");
	std::string password("");

	user.getUserDecision(userInputStr);
	userInput = userInputStr[0];

	if(userInput == '1'){
		user.getNewLength(length);
		password = generator.newPassword(length);
		generator.printPassword(password);
	}
	else if(userInput == '2'){
		user.getUserPassword(password);
		generator.modPassword(password);
		generator.printPassword(password);
	}
	else if(userInput == '3'){
		keyword.newPassword(password);
		generator.printPassword(password);
	}
	else{
		std::cout << "Error occurred." << std::endl;
		return 1;
	}

	modify.modifyDecision(userInput);

	if(userInput == 'Y'){
		userInput = modify.collectBadChars(password);
		if(userInput == 0){
			modify.replaceBadChars(password);
		}
		generator.printPassword(password);
	}
	else if(userInput == 'N'){
		std::cout << "Congrats! Here is your finalized password: "
				  << password << std::endl;
	}
	else{
		std::cout << "Error occurred." << std::endl;
		return 1;
	}

	return 0;
}
