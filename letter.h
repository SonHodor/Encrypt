#ifndef LETTER_H
#define LETTER_H
#include <string>

struct Letter
{
public:
	Letter(char c):ch(c){};
	Letter(int k):key(k){};
	Letter(std::string s):ab(s){};
	char ch;
	int key;
	std::string ab;
};

#endif
