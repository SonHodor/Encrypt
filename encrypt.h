#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>

class encrypt
{
    public:
        std::string mess;
	    int g;
	    std::vector <Letter> message;
	    int caeKey = 3;

	    encrypt(std::string m);
	    encrypt();

        void choise(char ch);

    private:
        std::string alphBecon = "abcdefghijklmnopqrstuvwxyz.,'!? a";
	    std::string beconAB = "aaaaabbbbbabbbaabbababbaaababaabaaaaa";

};

#endif // ENCRYPT_H
