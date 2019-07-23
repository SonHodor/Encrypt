#include "letter.h"
#include "encrypt.h"
#include <string>
#include <iostream>
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
    Letter * m;

    for (int i;i<MESS_SIZE;++i)
    {        
        //generating vector for message
        message.push_back(Letter(&mess[i]));
        m = & message[i];
        m->key = (int)ALPH_BECON.find(mess[i]);

        //'if char is not in alphabet' ch = space
        if(m->key<0) m->key = 31;

        //encrypting just if ch is letter
        if(m->key<26) m->key = (m->key + caeKey) % 26;

        //convert key to ch
        m->ch = ALPH_BECON[m->key];

        cout<<m->ch;
    }
}

void encrypt::becon(){
    Letter * m;
    for (int i;i<MESS_SIZE;++i)
    {
        //TODO: rewrite to 1 line
        message.push_back(Letter(&mess[i]));
        m = & message[i];
        m->key = (int)ALPH_BECON.find(mess[i]);

        m->ab = AB_BECON.substr(m->key,5);

        cout<<m->ab;
    }
    cout<<endl;
}

void encrypt::vernam(){
    vector<Letter> vernamKey;
    cout<< "Your message is between arrows >";
    srand(time(0));

    for (int i;i<MESS_SIZE;++i)
    {
        //generating vector for message
        message.push_back(Letter(&mess[i]));
        Letter * m = & message[i];
        m->key = (int)ALPH_BECON.find(mess[i]);
        string abCode = AB_BECON.substr(m->key,5);

        // generating vector of Letters from random keys
        vernamKey.push_back(Letter(rand() % 32));
        Letter * v = & vernamKey[i];
        v->ab = AB_BECON.substr(v->key,5);

        //generating ab code for [i] char
        m->ab = "";
        for (int j = 0; j < 5; j++){
            m->ab += help(&abCode[j], &v->ab[j]);
        }
        
        //converting ab keys to ch
        m->ch = ALPH_BECON[AB_BECON.find(m->ab)];
        v->ch = ALPH_BECON[v->key];

        cout<<m->ch;
    }
    cout<<"<\n"<<endl<<"Your key is between arrows >"; //'between arrows' because space can be a part of a key
    for(int i;i<MESS_SIZE;++i)
        cout<<vernamKey[i].ch;
    cout<<'<'<<endl;
}

char encrypt::help(const char * v1,const char * v2)
{
    //TODO: replase random here
    return ((*v1=='a'&&*v2=='a')||(*v1=='b'&&*v2=='b'))?'a':'b';
}

int encrypt::caeKey = 0;
string encrypt::ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
string encrypt::AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";