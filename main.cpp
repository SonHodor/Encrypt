#include <iostream>
#include <string>
#include "decrypt.h"
#include "encrypt.h"

using namespace std;

int main()
{
	bool work = true;
	string mess;
	while (true) {

		////////////PLEASE REWORK IT LATER/////////////

		cout << endl << "Print your message or 'q' to exit: ";
		cin >> mess;
		///////////////////////////////////////////////
		if(mess == "q") break;

		decrypt de(mess);
		encrypt en(mess);

		char choise;
		cout << "\nWhat do you want to do with text?\n1.Encrypt\n2.Decrypt\n: ";
		cin >> choise;
		switch (choise) {
		case '1':              //Encrypt
			cout << "\nWhat do you want to use?\n1.Caesar.\n2.Becon.\n3.Vernam." << endl;
			cin >> choise;
			en.choise(choise);
			break;
		case '2':              //Decrypt
			cout << "\nWhat do you want to use?\n1.Caesar.\n2.Becon.\n3.Vernam." << endl;
			cin >> choise;
			de.choise(choise);
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
