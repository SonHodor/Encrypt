#ifndef DECRYPT_H
#define DECRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>

/* TODO:
 * Make a prototype class for decrypt and encrypt
 */

class decrypt
{
public:
	decrypt(const std::string & m); //define the message size variables
	decrypt();

	void choise(const char & ch); //chiose between 3 methods of decryption

private:
	void caesar();
	void becon();
	void vernam();
	
	std::string getInput(); 	//
	std::string getOutput(); 	//
	std::string getVernamKey(); //
	void setCaesarKey(int key); //

	char help(const char & v1, const char & v2); //method for vernam(), basicaly it's XOR for chars

	int BECON_MESS_SIZE; //length of beacon encrypted cypher
	int MESS_SIZE; //length of message
	static int caeKey; //holds key for caesar decrypt
	static std::string ALPH_BECON; //holds alphabet of symbols
	static std::string AB_BECON; //holds a beacon key

	std::string mess; //holds user input
	std::string outputMess; //holds user output
	std::string vernamKey; //holds vernam encryption key

	Letter * message; //holds struct arr
};

#endif // DECRYPT_H
