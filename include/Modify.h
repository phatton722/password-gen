/* Modify.h */

#include <iostream>
#include <vector>

class Modify{
public:
	void modifyDecision(char&);
	int collectBadChars(std::string&);
	void replaceBadChars(std::string&);
	std::vector<char> badChars;
	std::vector<char>::iterator itr = badChars.begin();
};
