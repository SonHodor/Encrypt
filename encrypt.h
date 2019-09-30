#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>

/* TODO:
 * Make a prototype class for decrypt and encrypt
 */

class encrypt
{
public:
	encrypt(const std::string & m); //define the message size var
	encrypt();
	~encrypt();

	void choise(const char & ch); //chiose between 3 methods of encryption

	std::string getInput();
	std::string getOutput();
	std::string getVernamKey();
	void setCaesarKey(int key);

	void caesar();
	void becon();
	void vernam();

private:

	char randCh(char & v1); //method for vernam(), basicaly it's XOR for chars

	std::string mess; //holds user input
	std::string outputMess; //holds user output
	std::string vernamKey; //holds vernam encryption key

	Letter * message; // holds struct array

	int MESS_SIZE; //length od message
	static int caeKey; //holds key for caesar encrypt
	static std::string ALPH_BECON; //holds alphabet of symbols
	static std::string AB_BECON; //holds a beacon key

};

#endif // ENCRYPT_H
