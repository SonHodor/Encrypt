#ifndef DECRYPT_H
#define DECRYPT_H
#include "letter.h"
#include <iostream>
#include <vector>



class decrypt
{
    public:
        std::string mess;
	    int lengthStr;
	    std::vector <Letter> message;
	    int caeKey = 0;

	    decrypt(std::string m);
	    decrypt();

        void choise(char ch);

    private:
};

#endif // DECRYPT_H
