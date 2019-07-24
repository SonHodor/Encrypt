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
	Letter * m;

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message.push_back(Letter(&mess[i]));
		m = &message[i];
		m->key = (int)ALPH_BECON.find(mess[i]);

		//'if char is not in alphabet' ch = space
		if (m->key < 0) {
			m->key = 31;
		}

		//encrypting just if ch is letter
		if (m->key < 26) {
			m->key = (m->key - caeKey);
		}

		if (m->key < 0) {
			m->key += 26;
		}

		m->ch = ALPH_BECON[m->key];

		cout << m->ch;
	}
}

void decrypt::becon() {
	string abCode;
	Letter * m;

	for (int i; i < MESS_SIZE; i += 5)
	{
		//TODO: rewrite to 1 line, code is shit

		//generating vector for message
		abCode = mess.substr(i, 5);
		message.push_back(Letter(&abCode));
		m = &message[i];

		m->ch = ALPH_BECON[AB_BECON.find(abCode)];
		cout << m->ch;
	}
	cout << endl;
}

void decrypt::vernam() {
	vector<Letter> vernamKey;
	Letter * m;
	Letter * v;
	string keyMess;

	//TODO:
	////////////PLEASE REWORK IT LATER/////////////
	cout << "Write your encryption key: ";
	cin.clear();
	while (true) {

		getline(cin, keyMess);
		if (keyMess.size() == 0)
			cout << ' ';
		else
			break;
	}
	////////////////REALY BAD INPUT////////////////

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message.push_back(Letter(&mess[i]));
		m = &message[i];
		m->key = (int)ALPH_BECON.find(mess[i]);
		string abCode = AB_BECON.substr(m->key, 5);

		//generating vector for key
		vernamKey.push_back(Letter(&keyMess[i])); //i fuckin' forgot here '&' and trying to find a problem for 30 minutes
		v = &vernamKey[i];
		v->key = (int)ALPH_BECON.find(v->ch);
		v->ab = AB_BECON.substr(v->key, 5);

		//generating ab code for [i] char
		m->ab = "";
		for (int j = 0; j < 5; j++) {
			m->ab += help(&abCode[j], &v->ab[j]);
		}

		m->ch = ALPH_BECON[AB_BECON.find(m->ab)];
		cout << m->ch;
	}
}

char decrypt::help(const char * v1, const char * v2)
{
	return ((*v1 == 'a'&&*v2 == 'a') || (*v1 == 'b'&&*v2 == 'b')) ? 'a' : 'b';
}

int decrypt::caeKey = 0;
string decrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string decrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";