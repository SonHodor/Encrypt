#include "letter.h"
#include "decrypt.h"
#include <iostream>

using namespace std;

decrypt::decrypt(string m)
    :mess(m) 
{
	cout<<"Welcome to decrypt"<<endl;
	lengthStr = int(m.length()) / 6 + 1;
}

decrypt::decrypt(){}

void decrypt::choise(char ch){
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