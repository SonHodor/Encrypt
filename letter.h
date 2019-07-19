#ifndef LETTER_H
#define LETTER_H

struct Letter
{
public:
	Letter(char c):ch(c){};
	Letter(int k):key(k){};
	char ch;
	int key;
	char ab[5];
};

#endif
