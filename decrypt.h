#ifndef DECRYPT_H
#define DECRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>



class decrypt
{
    public:
        std::string mess;
	    std::vector <Letter> message;
		int BECON_MESS_SIZE;
		int MESS_SIZE;
	    int caeKey = 0;

	    decrypt(std::string m);
	    decrypt();

        void choise(char ch);

    private:
		void caesar();
		void becon();
		void vernam();
		
        std::string ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
	    std::string AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";
};

#endif // DECRYPT_H
