#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>

class encrypt
{
    public:
        std::string mess;
	    std::vector <Letter> message;
		int MESS_SIZE;
		int caeKey = 3;

	    encrypt(std::string m);
	    encrypt();

        void choise(char ch);

    private:

		void caesar();
		void becon();
		void vernam();

        std::string ALPH_BECON = "abcdefghijklmnopqrstuvwxyz.,'!? a";
	    std::string AB_BECON = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";

};

#endif // ENCRYPT_H
