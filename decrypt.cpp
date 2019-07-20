#include "letter.h"
#include "decrypt.h"
#include <iostream>
#include <ctime>
#include <stdlib.h> 

using namespace std;

decrypt::decrypt(string m)
    :mess(m) 
{
	cout<<"Welcome to decrypt"<<endl;
	BECON_MESS_SIZE = int(m.length()) / 5;
    MESS_SIZE = m.length();
}

decrypt::decrypt(){}

void decrypt::choise(char ch){
    switch (ch){
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

void decrypt::caesar(){
    cout<<"Write Caesar key: "; 
    cin>>caeKey;

    for (int i;i<MESS_SIZE;++i)
    {
        message.push_back(Letter(mess[i]));
        message[i].key = (int)ALPH_BECON.find(mess[i]);

        if(message[i].key<0) message[i].key = 31;

        if(message[i].key<26)
            message[i].key = (message[i].key - caeKey);

        if(message[i].key<0) message[i].key += 26;
        message[i].ch = ALPH_BECON[message[i].key];

        cout<<message[i].ch;
    }
}

void decrypt::becon(){
    string abCode;
    for (int i; i < MESS_SIZE; i += 5)
    {
        abCode = mess.substr(i, 5);
        message.push_back(Letter(abCode));


        message[i].ch = ALPH_BECON[AB_BECON.find(abCode)];

        cout<<message[i].ch;
    }
    cout << endl;
}

void decrypt::vernam(){
    vector<Letter> vernamKey;
    srand(time(0));
    string keyMess;
    ////////////PLEASE REWORK IT LATER/////////////
		cout << "Write your encryption key: ";
		while (true) {

			getline(cin, keyMess);
			if (keyMess.size() == 0)
				cout << ' ';
			else
				break;
		}
    ////////////////REALY BAD INPUT////////////////
    
    for (int i;i<MESS_SIZE;++i)
    {
        message.push_back(Letter(tolower(mess[i])));
        message[i].key = (int)ALPH_BECON.find(mess[i]);
        string abCode = AB_BECON.substr(message[i].key,5);

        vernamKey.push_back(Letter(keyMess[i]));
        vernamKey[i].key = ALPH_BECON.find(vernamKey[i].ch);
        vernamKey[i].ab = AB_BECON.substr(vernamKey[i].key,5);

        message[i].ab = "";
        for (int j = 0; j < 5; j++){
            message[i].ab += help(abCode[j], vernamKey[i].ab[j]);
        }
        
        message[i].ch = ALPH_BECON[AB_BECON.find(message[i].ab)];
        cout<<message[i].ch;
    }
}

char decrypt::help(char v1, char v2)
{
    return ((v1=='a'&&v2=='a')||(v1=='b'&&v2=='b'))?'a':'b';
}

int decrypt::caeKey = 0;
string decrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string decrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";