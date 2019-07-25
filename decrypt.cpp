#include "letter.h"
#include "decrypt.h"
#include <iostream>

using namespace std;

decrypt::decrypt(string m)
	:mess(m)
{
	BECON_MESS_SIZE = int(m.length()) / 5;
	MESS_SIZE = m.length();
}

decrypt::decrypt() {}

void decrypt::choise(const char ch) {
	switch (ch) {
	case '1':
		caesar();
		break;
	case '2':
		becon();
		break;
	case '3':
		vernam();
		break;
	default:
		break;
	}
}

void decrypt::caesar() {
	cout << "Write Caesar key: ";
	cin >> caeKey;

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message = new Letter(&mess[i]);
		message->key = (int)ALPH_BECON.find(mess[i]);

		//'if char is not in alphabet' ch = space
		if (message->key < 0) {
			message->key = 31;
		}

		//encrypting just if ch is letter
		if (message->key < 26) {
			message->key = (message->key - caeKey);
		}

		if (message->key < 0) {
			message->key += 26;
		}

		message->ch = ALPH_BECON[message->key];

		cout << message->ch;
		message++;
	}
	delete[] message;
}

void decrypt::becon() {
	for (int i; i < MESS_SIZE; i += 5)
	{
		/*
		 * get substring from message,
		 * find index of this substring in AB_BECON string
		 * and output char of ALPH_BECON under this index
		 */
		cout << ALPH_BECON[AB_BECON.find(mess.substr(i, 5))];
	}
	cout << endl;
}

void decrypt::vernam() {
	Letter * vernam;
	string keyMess;

	cout << "Write your encryption key: ";
	while (true) 
	{
		getline(cin, keyMess);
		if (keyMess.size() != 0) break;
	}

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message = new Letter(&mess[i]);
		message->key = (int)ALPH_BECON.find(message->ch);
		string abCode = AB_BECON.substr(message->key, 5);

		//generating vector for key
		vernam = new Letter(&keyMess[i]);
		//cout<<vernam->ch;
		vernam->key = (int)ALPH_BECON.find(vernam->ch);
		vernam->ab  = AB_BECON.substr(vernam->key, 5);

		//generating ab code for [i] char
		message->ab = "";
		for (int j = 0; j < 5; j++) {
			message->ab += help(abCode[j], vernam->ab[j]);
		}

		message->ch = ALPH_BECON[AB_BECON.find(message->ab)];
		cout << message->ch;
		message++;
		vernam++;
	}
	delete[] message;
	delete[] vernam;
}


char decrypt::help(const char & ch1, const char & ch2)
{
	return ((ch1 == 'a'&&ch2 == 'a') || (ch1 == 'b'&&ch2 == 'b')) ? 'a' : 'b';
}

int decrypt::caeKey = 0;
string decrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string decrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";