#include "letter.h"
#include "decrypt.h"
#include <iostream>

using namespace std;

decrypt::decrypt() {}
decrypt::decrypt(const string & m) :mess(m) {
	BECON_MESS_SIZE = int(m.length()) / 5;
	MESS_SIZE = m.length();
}

void decrypt::choise(const char & ch) {
	switch (ch) {
	case '1':
		caesar();
		cout << getOutput();
		break;
	case '2':
		becon();
		cout << getOutput();
		break;
	case '3':
		vernam();
		cout << getOutput();
		break;
	default:
		break;
	}
}

void decrypt::caesar() {
	if (mess.length() <= 0) throw "input message is null";
	outputMess = "";

	message = new Letter[MESS_SIZE];
	cout << "Write Caesar key: ";
	cin >> caeKey;

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message[i] = Letter(mess[i]);
		message[i].key = (int)ALPH_BECON.find(mess[i]);

		//'if char is not in alphabet' ch = space
		if (message[i].key < 0) message[i].key = 31;
		
		//encrypting just if ch is letter
		if (message[i].key < 26) message[i].key = (message[i].key - caeKey);
		
		if (message[i].key < 0) message[i].key += 26;

		message[i].ch = ALPH_BECON[message[i].key];

		outputMess += message[i].ch;
	}
	delete[] message;
}

void decrypt::becon() {
	if (mess.length() <= 0) throw "input message is null";
	outputMess = "";

	for (int i = 0; i < MESS_SIZE; i += 5)
	{
		if ((int)AB_BECON.find(mess.substr(i, 5)) < 0) {
			throw "this is not Becon";
		}

		/*
		* get substring from message,
		* find index of this substring in AB_BECON string
		* and output char of ALPH_BECON under this index
		*/
		outputMess += ALPH_BECON[AB_BECON.find(mess.substr(i, 5))];
	}
}

void decrypt::vernam() {
	if (mess.length() <= 0) throw "input message is null";
	outputMess = "";

	message = new Letter[MESS_SIZE];
	Letter * vernam = new Letter[MESS_SIZE];

	cout << "Write your encryption key: ";
	while (true) 
	{
		getline(cin, vernamKey);
		if (vernamKey.size() != 0) break;
	}

	if (mess.length() != vernamKey.length()) throw "length of message and vernam are not equal";

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message[i] = Letter(mess[i]);
		message[i].key = (int)ALPH_BECON.find(message[i].ch);
		string abCode = AB_BECON.substr(message[i].key, 5);

		//generating vector for key
		vernam[i] = Letter(vernamKey[i]);
		//cout<<vernam->ch;
		vernam[i].key = (int)ALPH_BECON.find(vernam[i].ch);
		vernam[i].ab  = AB_BECON.substr(vernam[i].key, 5);

		//generating ab code for [i] char
		message[i].ab = "";
		for (int j = 0; j < 5; j++) {
			message[i].ab += help(abCode[j], vernam[i].ab[j]);
		}

		outputMess += ALPH_BECON[AB_BECON.find(message[i].ab)];
	}
	delete[] message;
	delete[] vernam;
}


std::string decrypt::getInput(){
	return mess;
}

std::string decrypt::getOutput(){
	if(outputMess.length() > 0)
		return outputMess;
	else
		throw "output is empty. Did you encrypt message?";
}

void decrypt::setCaesarKey(int key){
	caeKey = key;
}

char decrypt::help(const char & ch1, const char & ch2)
{
	return ((ch1 == 'a'&&ch2 == 'a') || (ch1 == 'b'&&ch2 == 'b')) ? 'a' : 'b';
}

int decrypt::caeKey = 0;
string decrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a"; //All alphabet of encrypted letters
string decrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa"; //Beacon encryption key, a=aaaaa, b=aaaab, etc