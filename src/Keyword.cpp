/* Keyword.cpp */
#include <iostream>
#include <string>
#include <ctime>
#include "../include/Keyword.h"
#include "../include/Clear.h"

void Keyword::newPassword(std::string& password){

	Clear clr;
	bool done = 0;
	int addedLength = 0;
	char addedChar = 0;

	srand(time(nullptr));

	std::cout << "What keyword would you like to use with "
			  << "your new password? Maximum length is 8 characters: ";

	do{
		std::cin >> password;

		if(std::cin.fail()){
			clr.errorMessage();
			clr.resetBuffer();
			password.clear();
		}
		else if(password.length() < 1 || password.length() > 8){
			clr.errorMessage();
			clr.resetBuffer();
			password.clear();
		}
		else{
			done = 1;
		}

	} while(done == 0);

	addedLength = rand()%10+1;
	done = 0;

	do{
		++addedLength;
	} while((password.length() + addedLength) < 6);

	for(int i=0; i<addedLength; i++){
		addedChar = (unsigned char)(rand()%94+33);
		std::cout << "addedChar = " << addedChar << std::endl;
		password.push_back(addedChar);
	}
	
	clr.resetBuffer();
}
