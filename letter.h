#ifndef LETTER_H
#define LETTER_H
#include <cctype>
#include <string>

/* TODO:
 * create new branch, where Letter will rewrite to class 
 */

struct Letter
{
public:
	// CONSTRUCTORS //
	Letter(){};
	Letter(char * c) :ch(tolower(*c)) {}; //sets ch var
	Letter(int k) :key(k) {}; //sets key var
	Letter(std::string * s) :ab(*s) {}; //sets ab var
	//////////////////

	char ch;
	int key;
	std::string ab;
};

#endif
