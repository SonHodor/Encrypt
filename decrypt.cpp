#include "letter.h"
#include "decrypt.h"
#include <iostream>

using namespace std;

decrypt::decrypt(string m)
    :mess(m) 
{
	cout<<"Welcome to decrypt"<<endl;
	BECON_MESS_SIZE = int(m.length()) / 6 + 1;
    MESS_SIZE = m.length();
}

decrypt::decrypt(){}

void decrypt::choise(char ch){
    switch (ch){
    case '1'://Caesar
        caesar();
        break;
    case '2'://Becon
        becon();
        break;
    case '3'://Vernam
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

}

void decrypt::vernam(){
    
}
