#include "std_lib_facilities.h"





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


int whereChar(char x){
    if((x>96)&&(x<123)){

        return binSearchLetter("abcdefghijklmnopqrstuvwxyz",0,26,x)-97;
    }else{

        return switSearch(x);
    }
}



int main()
{
    
    
    string mess;
    getline(cin,mess);


    
    cout<<mess.length()<<endl;
    int kek[mess.length()];
    for (int i = 0; i < mess.length(); ++i)
    {
        kek[i] = whereChar(mess[i]);
        cout<<i<<"  "<<kek[i]<<endl;
    }

    return 0;
}
