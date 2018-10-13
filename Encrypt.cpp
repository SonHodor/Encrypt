#include "std_lib_facilities.h"
//
//Program was absolutly re-writed, I mooved all encrypting actions from *main* to *encrypt* class
//







class letter
{
public:
    char letCh;
    int letKey;
    char letCh5B[5];
    letter(char ch)
        :letCh(ch){}
    letter();

    void keyTo5bArr()
    {
        string beconAB = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";
        for (int i = 0; i < 5; ++i)
        {
            letCh5B[i] = beconAB[letKey+i];
        }
    }

    void charToBeconKey()
    {
        if((letCh>96)&&(letCh<123)){

        letKey = binSearchLetter("abcdefghijklmnopqrstuvwxyz",0,26,letCh)-97;
        }else{

        letKey = switSearch(letCh);
        }
    }

    void printArr()
    {
        for (int i = 0; i < 5; ++i)
        {
            cout<<letCh5B[i]<<' ';
        }
        cout<<endl;
    }
private:

    int binSearchLetter(string str, int l, int r, char x){
        int help = l+(r-l)/2;
        if (str[help]==x)
            return x;
        if (str[help] > x)
            return binSearchLetter(str, l, help-1, x);
        return binSearchLetter(str, help+1, r, x);
    }

    int switSearch(char x){
        switch(x){
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
                cout<<"chto to ne tak";
        }
    }

};


class encrypt
{
public:
    string mess;
    int g;
    letter message[];

    encrypt(string m)
        :mess(m){
        	
        }
    encrypt();

    void fillArr(){
        for (int i = 0; i < mess.length(); ++i)
        {
            message[i].letCh = mess[i];
            message[i].charToBeconKey();
            message[i].keyTo5bArr();
        }
    }

    void showMess(){
        for (int i = 0; i < mess.length(); ++i)
        {
            message[i].printArr();
        }

    }
};







int main()
{


    string mess;
    getline(cin,mess);

    encrypt messageEnc(mess);
    messageEnc.fillArr();
    messageEnc.showMess();
    cout<<"kek"<<endl;



    return 0;
}
