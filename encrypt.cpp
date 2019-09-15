#include "letter.h"
#include "encrypt.h"
#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h> 


using namespace std;

encrypt::encrypt(const string & m)
	:mess(m) {
	MESS_SIZE = m.length();
}

encrypt::encrypt() {}
encrypt::~encrypt() {}

void encrypt::choise(const char & ch) {
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

void encrypt::caesar() {
	if (mess.length() <= 0) throw "input message is null";

	message = new Letter[MESS_SIZE];
	cout << "Write Caesar key: ";
	cin >> caeKey;

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message[i] = Letter(mess[i]);
		message[i].key = (int)ALPH_BECON.find(mess[i]);

		//'if char is not in alphabet' ch = space
		if (message[i].key < 0)message[i].key = 31;

		//encrypting just if ch is letter
		if (message[i].key < 26) message[i].key = (message[i].key + caeKey) % 26;

		//convert key to ch
		message[i].ch = ALPH_BECON[message[i].key];

		cout << message[i].ch;
	}
	delete[] message;
}

void encrypt::becon() {
	if (mess.length() <= 0) throw "input message is null";

	message = new Letter[MESS_SIZE];

	for (int i; i < MESS_SIZE; ++i)
	{
		message[i] = Letter(mess[i]);

		//find index of [i] ch in mess in ALPH_BECON and set it like a key
		message[i].key = (int)ALPH_BECON.find(mess[i]);

		//if can't find set 'space' key, which is 31
		if (message[i].key < 0)message[i].key = 31;

		//get substring by key with length 5
		message[i].ab = AB_BECON.substr(message[i].key, 5);

		cout << message[i].ab;
	}
	cout << endl;
	delete[] message;
}

void encrypt::vernam() {
	if (mess.length() <= 0) throw "input message is null";

	string vernam;
	srand(time(0));
    message = new Letter[MESS_SIZE];
	
    //'between arrows' because space can be a part of a key
    cout << endl << "Your message is between arrows >"; 

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message[i] = Letter(mess[i]);
		message[i].key = (int)ALPH_BECON.find(message[i].ch);
		message[i].ab = AB_BECON.substr(message[i].key, 5);

		//generating vernam ab
		string verCh = "";
		for (int j = 0; j < 5; j++) 
		{
			verCh += randCh(message[i].ab[j]);
		}
		//converting vernam ab to char
		vernam += ALPH_BECON[AB_BECON.find(verCh)];

		//converting message[i] from ab to char
		message[i].ch = ALPH_BECON[AB_BECON.find(message[i].ab)];
		cout<<message[i].ch;
	}
	cout << "<\n" << "Your key is between arrows >"<< vernam << '<' << endl;
	delete[] message;
}

char encrypt::randCh(char & v1) {
    char v2 = ALPH_BECON[rand() % 2]; //'a' or 'b'
    v1 = ((v1 == 'a'&&v2 == 'a') || (v1 == 'b'&&v2 == 'b')) ? 'a' : 'b';
    return v2;
}

int encrypt::caeKey = 0;
string encrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string encrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";