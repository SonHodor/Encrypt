#include "letter.h"
#include "encrypt.h"
#include <iostream>

using namespace std;

encrypt::encrypt(string m)
    :mess(m){
    cout<<"Welcome to encrypt"<<endl;
}

encrypt::encrypt(){}

void encrypt::choise(char ch){
    switch (ch){
    case '1'://Caesar
        cout<<"You just choose caesar"<<endl;
        break;
    case '2'://Becon
        //
        break;
    case '3'://Vernam
        //
        break;
    default:
        break;
    }
}