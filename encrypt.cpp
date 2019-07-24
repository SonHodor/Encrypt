#include "letter.h"
#include "encrypt.h"
#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h> 


using namespace std;

encrypt::encrypt(string m)
	:mess(m) {
	MESS_SIZE = m.length();
}

encrypt::encrypt() {}

void encrypt::choise(char ch) {
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
		if (m->key < 0)m->key = 31;

		//encrypting just if ch is letter
		if (m->key < 26) m->key = (m->key + caeKey) % 26;

		//convert key to ch
		m->ch = ALPH_BECON[m->key];

		cout << m->ch;
	}
}

void encrypt::becon() {
	Letter * m;
	for (int i; i < MESS_SIZE; ++i)
	{
        /*
         * find index of [i] letter in message 
         * and output substring by this index 
         * with length 5
         */
		cout << AB_BECON.substr(ALPH_BECON.find(mess[i]), 5);
	}
	cout << endl;
}

void encrypt::vernam() {
	string vernamKey;
	srand(time(0));
    
    //'between arrows' because space can be a part of a key
    cout << endl << "Your key is between arrows >"; 

	for (int i; i < MESS_SIZE; ++i)
	{
		//generating vector for message
		message.push_back(Letter(&mess[i]));
		Letter * m = &message[i];
		m->key = (int)ALPH_BECON.find(mess[i]);
		m->ab = AB_BECON.substr(m->key, 5);

		//generating and output vernam key ch
        vernamKey = "";
		for (int j = 0; j < 5; j++)
			vernamKey += randCh(&m->ab[j]);
        cout<<ALPH_BECON[AB_BECON.find(vernamKey)];

		//converting ab keys to ch
		m->ch = ALPH_BECON[AB_BECON.find(m->ab)];
	}

	cout << "<\n" << "Your message is between arrows >";
	for (int i; i < MESS_SIZE; ++i)
		cout << message[i].ch;
	cout << '<' << endl;
}

char encrypt::randCh(char * v1) {
    char v2 = (rand() % 2 == 0) ? 'a' : 'b';
    *v1 = ((*v1 == 'a'&&v2 == 'a') || (*v1 == 'b'&&v2 == 'b')) ? 'a' : 'b';
    return v2;
}

int encrypt::caeKey = 0;
string encrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string encrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";