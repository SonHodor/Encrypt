#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>

class encrypt
{
    public:
	    encrypt(std::string m);
	    encrypt();

        void choise(char ch);

    private:

		void caesar();
		void becon();
		void vernam();

		char help(char v1, char v2);

		std::string mess;
	    std::vector <Letter> message;
		int MESS_SIZE;
		static int caeKey;
        static std::string ALPH_BECON;
	    static std::string AB_BECON;

};

#endif // ENCRYPT_H
