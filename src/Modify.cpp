/* Modify.cpp */

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../include/Modify.h"
#include "../include/Clear.h"

void Modify::modifyDecision(char& answer){

	Clear clr;
	bool done = 0;

	std::cout << "Are there characters in your password you would like "
			  << "removed? [Y/y/N/n]: ";

	do{
		std::cin >> answer;
		answer = toupper(answer);

		if(answer == 'Y' || answer == 'N'){
			done = 1;
		}
		else{
			clr.errorMessage();
			clr.resetBuffer();
			answer = 0;
		}
			
	} while(done == 0);
}

int Modify::collectBadChars(std::string& password){

	bool done = 0;
	char temp = 0;
	Clear clr;

	std::cout << "Please enter the characters that you "
			  << "would like removed/excluded from your current password. "
			  << "Please enter 'z' when you are finished. " 
			  << "(Note: the only character you cannot replace is 'z')"
			  << std::endl;
	clr.resetBuffer();

	do{
		std::cin >> temp;

		if(std::cin.fail()){
			clr.errorMessage();
			clr.resetBuffer();
		}

		else if(temp == 'z'){
			if(badChars.size() == 0){
				std::cout << "Are you sure you don't want to replace any "
					      << "unwanted characters? [Y/y/N/n]: ";

				bool done_ = 0;

				do{
					clr.resetBuffer();
					std::cin >> temp;
					temp = toupper(temp);

					if(temp == 'Y'){
						std::cout << "Here is your finalized "
								  << "password: " << password << std::endl;
						return 1;
					}
					else if(temp == 'N'){
						std::cout << "What characters would you like "
								  << "to remove/exclude? Please enter 'z' when "
								  << "you are finished: ";
						done_ = 1;
					}
					else{
						clr.errorMessage();
						clr.resetBuffer();
						break;
					}
				} while(done_ = 0);
			}
			else{
				done = 1;
			}
		}

		else{
			badChars.push_back(temp);
		}	

	} while(done == 0);
	
	return 0;
}

void Modify::replaceBadChars(std::string& password){

	srand(time(nullptr));

	bool done = 0;

	do{
		loop:
		for(itr = badChars.begin(); itr != badChars.end(); itr++){
			for(int i=0; i<password.length(); i++){
				if(*itr == password.at(i)){
					do{
						std::cout << "Changing string element: ";
						std::cout << password.at(i) << "-->";
						password.at(i) = 
							(unsigned char)(rand()%94 + (unsigned)33);
						std::cout << password.at(i) << std::endl;
					} while(*itr == password.at(i));
				}
			}
		} 

		for(itr = badChars.begin(); itr != badChars.end(); itr++){
			for(int i=0; i<password.length(); i++){
				if(*itr == password.at(i)){
					done = 0;
					goto loop;
				}
				else{
					done = 1;
				}
			}
		}
	} while(done == 0);
}
