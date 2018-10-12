#include "std_lib_facilities.h"
//
//Hi! Half of this code doesn't work how it must
//but..
//It's just First commit!



//D:\Programming\Ready-C++\SomeBadProject



class letMess
{
public:
    char letCh;
    int letKey;
    char letCh5B[5];
    letMess(char ch)
        :letCh(ch){}
    letMess()
        :letCh('a'){}




    void keyTo5bArr(){
        string beconAB = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";
        for (int i = 0; i < 5; ++i)
        {
            letCh5B[i] = beconAB[letKey+i];
        }

    }

    void charToBeconKey(){
        if((letCh>96)&&(letCh<123)){

        letKey = binSearchLetter("abcdefghijklmnopqrstuvwxyz",0,26,letCh)-97;
        }else{

        letKey = switSearch(letCh);
        }
    }

    void printArr(){
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




int main()
{


    string mess;
    getline(cin,mess);
    int g = mess.length();

    letMess k[g];
    for (int i = 0; i < g; ++i)
    {
        k[i].letCh = mess[i];
        k[i].charToBeconKey();
        k[i].keyTo5bArr();
        k[i].printArr();
    }



    return 0;
}
