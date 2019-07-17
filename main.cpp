// add new class Decrypt
// re-write class Encrypt, hide all func in classes from interface

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;//plivet

//
//Program was absolutly re-writed, I mooved all encrypting actions from *main* to *encrypt* class
//
class Letter
{
public:
	bool regis = false;
	char letCh;
	int letKey;
	char letCh5B[5];
	Letter(char ch)
		:letCh(ch) {

	}
	Letter() {};
	Letter(int key)
		:letKey(key) {}


	void keyTo5bArr();

	void charToIntKey();

	void showCh()
	{
		cout << letCh;
	}

	void keyToCh()
	{
		letCh = alphBecon[letKey];
	}

	void printArr5B()
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << letCh5B[i];
		}
		cout << ' ';
	}

	void abToInt()
	{
		int i = 0;
		while (i < 32)
		{
			bool k = letCh5B[0] == alph5B[i][0] &&
				letCh5B[1] == alph5B[i][1] &&
				letCh5B[2] == alph5B[i][2] &&
				letCh5B[3] == alph5B[i][3] &&
				letCh5B[4] == alph5B[i][4];
			if (k)
			{
				cout << "letKey = i" << endl;
				letKey = i;
				break;
			}
			i++;
		}
	}

	void caesarWithKey(int caeKey) {
		letKey += caeKey;
		while (true)
		{
			if (letKey > 31) {
				letKey -= 32;
			}
			else {
				break;
			}
		}
	}

	void toLower() {

		if (letCh < 91 && letCh > 64)
			regis = true;

		if (regis) {
			letCh += 32;
		}

		if (letCh > 123 && letCh < 96 && letCh != '.'  && letCh != ','
			&& letCh != '\'' && letCh != '!'
			&& letCh != '?'  && letCh != ' ')// if .letCh is out os alphabet (letter.alphBecon)
			letCh = ' ';
	}


private:

	string alphBecon = "abcdefghijklmnopqrstuvwxyz.,'!? a";
	string beconAB = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";
	char alph5B[32][5] = { {'a','a','a','a','a'},{'a','a','a','a','b'},{'a','a','a','b','b'},{'a','a','b','b','b'},{'a','b','b','b','b'},{'b','b','b','b','b'},
				   {'b','b','b','b','a'},{'b','b','b','a','b'},{'b','b','a','b','b'},{'b','a','b','b','b'},{'a','b','b','b','a'},{'b','b','b','a','a'},
				   {'b','b','a','a','b'},{'b','a','a','b','b'},{'a','a','b','b','a'},{'a','b','b','a','b'},{'b','b','a','b','a'},{'b','a','b','a','b'},
				   {'a','b','a','b','b'},{'b','a','b','b','a'},{'a','b','b','a','a'},{'b','b','a','a','a'},{'b','a','a','a','b'},{'a','a','a','b','a'},
				   {'a','a','b','a','b'},{'a','b','a','b','a'},{'b','a','b','a','a'},{'a','b','a','a','b'},{'b','a','a','b','a'},{'a','a','b','a','a'},
				   {'a','b','a','a','a'},{'b','a','a','a','a'} };

	int binSearchLetter(string str, int l, int r, char x) {
		int help = l + (r - l) / 2;
		if (str[help] == x)
			return x;
		if (str[help] > x)
			return binSearchLetter(str, l, help - 1, x);
		return binSearchLetter(str, help + 1, r, x);
	}

	int switSearch(char x) {
		switch (x) {
		case '.':
			return 26;
		case ',':
			return 27;
		case '\'':
			return 28;
		case '!':
			return 29;
		case '?':
			return 30;
		case ' ':
			return 31;
		default:
			cout << "chto to ne tak";
		}return NULL;
	}

};
void Letter::keyTo5bArr()
{
	//string beconAB = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";
	for (int i = 0; i < 5; ++i)
	{
		letCh5B[i] = beconAB[letKey + i];
	}
}
void Letter::charToIntKey()
{
	if ((letCh > 96) && (letCh < 123)) {
		letKey = binSearchLetter("abcdefghijklmnopqrstuvwxyz", 0, 26, letCh) - 97;
	}
	else {
		letKey = switSearch(letCh);
	}
}

class encrypt//ZASHIFROVKA
{
public:
	string mess;
	int g;
	vector <Letter> message;
	int caeKey = 3;

	encrypt(string m)
		:mess(m) {}
	encrypt() {};

	void choiseEnc(char chCh) {
		switch (chCh) {
		case '1':
			toAbOnly();
			break;
		case '2':
			toCaesarBasic();
			break;
		case '3':
			toAbCaesar();
			break;
		default:
			cout << "IDK" << endl;
			break;
		}
	}

	void toAbOnly()
	{
		messToKey();
		keyToMess5B();
		showMess5B();
	}

	void toAbCaesar() {
		cout << "Print caesar key to sipher: ";
		cin >> caeKey;
		messToKey();
		keyToCaesarKey();
		keyToMess5B();
		showMess5B();
	}

	void toCaesarBasic() {
		cout << "Print caesar key to encrypt: ";
		cin >> caeKey;
		cout << endl;
		messToKey();
		keyToCaesarKey();
		keyToMess();
		showMess();
	}

private:

	void messToKey() {
		for (int i = 0; i < mess.length(); ++i)
		{
			message.push_back(mess[i]);
			message[i].toLower();
			message[i].charToIntKey();
		}
	}

	void keyToMess5B() {
		for (int i = 0; i < mess.length(); i++)
		{
			message[i].keyTo5bArr();
		}
	}

	void keyToCaesarKey() {
		for (int i = 0; i < mess.length(); i++)
		{
			message[i].caesarWithKey(caeKey);
		}
	}

	void showMess5B() {
		for (int i = 0; i < mess.length(); ++i)
		{
			message[i].printArr5B();
		}
	}

	void showMess() {
		for (int i = 0; i < mess.length(); i++)
		{
			cout << message[i].letCh;
		}
	}

	void keyToMess() {
		for (int i = 0; i < mess.length(); i++)
		{
			message[i].keyToCh();
		}
	}
};

class decrypt //RASHIFROVKA
{
public:
	string mess;
	int lengthStr;
	vector <Letter> message;
	int caeKey = 0;

	decrypt(string m)
		:mess(m) {
		lengthStr = int(m.length()) / 6 + 1;
	}
	decrypt() {};

	void choiseDec(char chCh) {
		switch (chCh) {
		case '1':
			fromAbBasic();
			break;
		case '2':
			fromCaesarBasic();
			break;
		case '3':
			fromAbCaesar();
			break;
		case '4':
			tryDecCaesar();
		default:
			cout << "IDK" << endl;
			break;
		}
	}

	void tryDecCaesar() 
	{
		lengthStr = int(mess.length());
		messToKey();
		caeKey = 1;
		for (int i = 0; i < 32; i++)
		{
			keyToCaesarKey();
			keyToMess();
			cout << i << "- ";
			showMess();
			cout << '\n';
		}
	}

	void fromAbCaesar() {
		cout << "Print caesar key to decrypt: ";
		cin >> caeKey;
		cout << endl;

		while (true)
		{
			if (caeKey > 31) {
				caeKey -= 32;
			}
			else {
				caeKey = 32 - caeKey;
				break;
			}
		}
		strAbToKey();
		keyToCaesarKey();
		keyToChArr();
		showMess();
	}

	void fromCaesarBasic() {
		cout << "Print caesar key to decrypt: ";
		cin >> caeKey;
		cout << endl;

		while (true)
		{
			if (caeKey > 31) {
				caeKey -= 32;
			}
			else {
				caeKey = 32 - caeKey;
				break;
			}
		}
		lengthStr = int(mess.length());
		messToKey();
		keyToCaesarKey();
		keyToMess();
		showMess();
	}

	void fromAbBasic()
	{
		strAbToKey();
		keyToChArr();
		showMess();
	}

private:
	void messToKey() {
		for (int i = 0; i < mess.length(); ++i)
		{
			message.push_back(mess[i]);
			message[i].toLower();
			message[i].charToIntKey();
		}
	}

	void showMessCh() {
		for (int i = 0; i < lengthStr; ++i)
		{
			message[i].showCh();
		}

	}

	void keyToChArr()
	{
		for (int i = 0; i < lengthStr; ++i)
		{
			message[i].keyToCh();
		}
	}
	//for AB key to message

	void strAbToKey() {
		int g = lengthStr;
		
		bool isEquals;
		int i = 0, k = 0;


		while (g > 0)
		{
			isEquals = mess[k] == alph5B[i][0] &&
				mess[k + 1] == alph5B[i][1] &&
				mess[k + 2] == alph5B[i][2] &&
				mess[k + 3] == alph5B[i][3] &&
				mess[k + 4] == alph5B[i][4];

			if (isEquals)
			{
				message.push_back(i);
				k += 6;
				
				g -= 1;
				i = 0;
			}
			else {
				i++;
			}
		}
		
	}

	char alph5B[32][5] = { {'a','a','a','a','a'},{'a','a','a','a','b'},{'a','a','a','b','b'},{'a','a','b','b','b'},{'a','b','b','b','b'},{'b','b','b','b','b'},
				   {'b','b','b','b','a'},{'b','b','b','a','b'},{'b','b','a','b','b'},{'b','a','b','b','b'},{'a','b','b','b','a'},{'b','b','b','a','a'},
				   {'b','b','a','a','b'},{'b','a','a','b','b'},{'a','a','b','b','a'},{'a','b','b','a','b'},{'b','b','a','b','a'},{'b','a','b','a','b'},
				   {'a','b','a','b','b'},{'b','a','b','b','a'},{'a','b','b','a','a'},{'b','b','a','a','a'},{'b','a','a','a','b'},{'a','a','a','b','a'},
				   {'a','a','b','a','b'},{'a','b','a','b','a'},{'b','a','b','a','a'},{'a','b','a','a','b'},{'b','a','a','b','a'},{'a','a','b','a','a'},
				   {'a','b','a','a','a'},{'b','a','a','a','a'} };

	void keyToCaesarKey() {
		for (int i = 0; i < lengthStr; i++)
		{
			message[i].caesarWithKey(caeKey);
		}
	}

	void showMess() {
		for (int i = 0; i < lengthStr; i++)
		{
			cout << message[i].letCh;
		}
	}
	//for message key to message

	void keyToMess() {
		for (int i = 0; i < mess.length(); i++)
		{
			message[i].keyToCh();
		}
	}

	/*void toLower() {
		for (int i = 0; i < mess.length(); i++)
		{
			if (message[i].letCh < 91 && message[i].letCh > 64)
				message[i].regis = true;
		}

		for (int i = 0; i < mess.length(); i++)
		{
			if (message[i].regis)
				message[i].letCh += 32;
			if (message[i].letCh > 123 && message[i].letCh < 96 && message[i].letCh != '.'  && message[i].letCh != ','
				&& message[i].letCh != '\'' && message[i].letCh != '!'
				&& message[i].letCh != '?'  && message[i].letCh != ' ')// if .letCh is out os alphabet (letter.alphBecon)
				message[i].letCh = ' ';
		}
	}*/
};



int main()
{
	bool work = true;
	string mess;
	while (work) {
		
		////////////PLEASE REWORK IT LATER/////////////

		cout << endl << "Print your message" << endl;
		while (true) {

			getline(cin, mess);
			if (mess.size() == 0)
				cout << ' ';
			else
				break;
		}

		decrypt messageDec(mess);
		encrypt messageEnc(mess);

		char choise;
		char chCh;
		cout << "What do you want to do with text?\n1.Decrypt\n2.Encrypt\n\nIf you want to exit program enter 0\n";
		cin >> choise;
		switch (choise) {
		case'0':			   //EXIT
			work = false;
			break;
		case '1':              //Decrypt
			cout << "What do you want to use?\n1.Only Bacon.\n2.Only Caesar.\n3.Caesar with Bacon." << endl;
			cin >> chCh;
			messageDec.choiseDec(chCh);
			break;
		case '2':              //Encrypt
			cout << "What do you want to use?\n1.Only Bacon.\n2.Only Caesar.\n3.Caesar with Bacon." << endl;
			cin >> chCh;
			messageEnc.choiseEnc(chCh);
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
