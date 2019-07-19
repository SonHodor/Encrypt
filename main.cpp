#include <iostream>
#include <string>
#include "decrypt.h"
#include "encrypt.h"

using namespace std;

int main()
{
	bool work = true;
	string mess;
	while (work) {

		////////////PLEASE REWORK IT LATER/////////////

		cout << endl << "Print your message" << endl;
		cin >> mess;
		///////////////////////////////////////////////

		decrypt de;
		encrypt en;

		char choise;
		cout << "What do you want to do with text?\n1.Encrypt\n2.Decrypt\n\nIf you want to exit program enter 0\n";
		cin >> choise;
		switch (choise) {
		case '0':			   //EXIT
			work = false;
			break;
		case '1':              //Decrypt
			cout << "What do you want to use?\n1.Bacon.\n2.Caesar.\n3.Vernam." << endl;
			cin >> choise;
			de.choise(choise);
			break;
		case '2':              //Encrypt
			cout << "What do you want to use?\n1.Bacon.\n2.Caesar.\n3.Vernam." << endl;
			cin >> choise;
			en.choise(choise);
			break;
		default:
			cout << "I can't understand, write 0, 1 or 2\n";
		}
	}

	cout << endl << "Bye-Bye))" << endl;
	////////Debug for Bacon Only//////////////
	//bbbab aabba baaab baaaa aabbb aabba baaaa aabab aabba abbaa baaaa aabbb aabba bbabb baabb baaba abaaa aaaaa baaaa

	////////Debug for Caesar with key = 15////
	//?xs!apbtbkobpbpxctowdxmmmm

	return 0;
}
