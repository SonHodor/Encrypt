#ifndef DECRYPT_H
#define DECRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>



class decrypt
{
    public:
	    decrypt(std::string m);
	    decrypt();

        void choise(char ch);

    private:
		void caesar();
		void becon();
		void vernam();
		
		char help(char v1, char v2);
		
		std::string mess;
	    std::vector <Letter> message;
		int BECON_MESS_SIZE;
		int MESS_SIZE;
		static int caeKey;
        static std::string ALPH_BECON;
	    static std::string AB_BECON;
};

#endif // DECRYPT_H
