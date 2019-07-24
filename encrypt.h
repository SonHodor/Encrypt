#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>

class encrypt
{
public:
	encrypt(std::string m); //define the message size var
	encrypt();

	void choise(char ch); //chiose between 3 methods of encryption

private:

	void caesar();
	void becon();
	void vernam();

	char randCh(char * v1); //method for vernam(), basicaly it's XOR for chars

	std::string mess; //holds message input

	//TODO: rewrite whole program from vectors to arrays
	std::vector <Letter> message; // holds struct arr

	int MESS_SIZE; //length od message
	static int caeKey; //holds key for caesar encrypt
	static std::string ALPH_BECON; //holds alphabet of symbols
	static std::string AB_BECON; //holds a beacon key

};

#endif // ENCRYPT_H
