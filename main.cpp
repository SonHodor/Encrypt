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

		cout << endl << "Print your message or 'q' to exit: ";
		while (true) 
		{
			getline(cin, mess);
			if (mess.size() != 0) break;
		}

		if (mess == "q") break;

		decrypt de(mess);
		encrypt en(mess);

		char choise;
		cout << "\n1.Encrypt\n2.Decrypt\nYou want to: ";
		cin >> choise;
		switch (choise) {
		case '1'://Encrypt
			cout << "\n1.Caesar.\n2.Becon.\n3.Vernam.\nAnd you want to use: ";
			cin >> choise;
			en.choise(choise);
			break;
		case '2'://Decrypt
			cout << "\n1.Caesar.\n2.Becon.\n3.Vernam.\nAnd you want to use: ";
			cin >> choise;
			de.choise(choise);
			break;

		default:
			cout << "I can't understand, write 0, 1 or 2\n";
		}
	}

	cout << endl << "Bye-Bye))" << endl;
	return 0;
}
