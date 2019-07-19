#include "letter.h"
#include "encrypt.h"
#include <iostream>
#include "cctype"


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
        cout<<mess[i];
    }
}

void encrypt::vernam(){
    for (int i;i<MESS_SIZE;++i)
    {
        cout<<mess[i];
    }
}
