#include "letter.h"
#include "encrypt.h"
#include <string>
#include <iostream>
#include <cctype>
#include <ctime>
#include <stdlib.h> 


using namespace std;

encrypt::encrypt(string m)
    :mess(m){
    MESS_SIZE = m.length();
}

encrypt::encrypt(){}

void encrypt::choise(char ch){
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

void encrypt::caesar(){

    cout<<"Write Caesar key: "; 
    cin>>caeKey;

    for (int i;i<MESS_SIZE;++i)
    {
        message.push_back(Letter(tolower(mess[i])));
        message[i].key = (int)ALPH_BECON.find(mess[i]);

        if(message[i].key<0) message[i].key = 31;

        if(message[i].key<26)
            message[i].key = (message[i].key + caeKey) % 26;

        message[i].ch = ALPH_BECON[message[i].key];

        cout<<message[i].ch;
    }
}

void encrypt::becon(){
    for (int i;i<MESS_SIZE;++i)
    {
        message.push_back(Letter(tolower(mess[i])));
        message[i].key = (int)ALPH_BECON.find(mess[i]);

        message[i].ab = AB_BECON.substr(message[i].key,5);

        cout<<message[i].ab;
    }
    cout<<endl;
}

void encrypt::vernam(){
    vector<Letter> vernamKey;
    cout<< "Your message is between arrows >";
    srand(time(0));

    for (int i;i<MESS_SIZE;++i)
    {        
        message.push_back(Letter(tolower(mess[i])));
        message[i].key = (int)ALPH_BECON.find(mess[i]);
        string abCode = AB_BECON.substr(message[i].key,5);

        // generating random key to vernam 
        vernamKey.push_back(Letter(rand() % 32));
        vernamKey[i].ab = AB_BECON.substr(vernamKey[i].key,5);

        message[i].ab = "";
        for (int j = 0; j < 5; j++){
            message[i].ab += help(abCode[j], vernamKey[i].ab[j]);
        }
        
        message[i].ch   = ALPH_BECON[AB_BECON.find(message[i].ab)];
        vernamKey[i].ch = ALPH_BECON[vernamKey[i].key];

        cout<<message[i].ch;
    }
    cout<<"<\n"<<endl<<"Your key is between arrows >";
    for(int i;i<MESS_SIZE;++i)
        cout<<vernamKey[i].ch;
    cout<<'<'<<endl;
}

char encrypt::help(char v1, char v2)
{
    return ((v1=='a'&&v2=='a')||(v1=='b'&&v2=='b'))?'a':'b';
}

int encrypt::caeKey = 0;
string encrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string encrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";