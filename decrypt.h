#ifndef DECRYPT_H
#define DECRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>



class decrypt
{
public:
	decrypt(std::string m); //define the message size variables
	decrypt();

	void choise(const char ch); //chiose between 3 methods of decryption

private:
	void caesar();
	void becon();
	void vernam();

	char help(const char & v1, const char & v2); //method for vernam(), basicaly it's XOR for chars

	std::string mess; //holds message input

	//TODO: rewrite whole program from vectors to arrays
	Letter * message; //holds struct arr

	int BECON_MESS_SIZE; //length of beacon encrypted cypher
	int MESS_SIZE; //length od message
	static int caeKey; //holds key for caesar decrypt
	static std::string ALPH_BECON; //holds alphabet of symbols
	static std::string AB_BECON; //holds a beacon key
};

#endif // DECRYPT_H
