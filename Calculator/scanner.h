#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "token.h"
#include "Fraction.h"
#include <queue>
class Scanner
{
    public:
        Scanner(): line(""), tokens(){};
        Token getNextToken();
    protected:
    private:
        //unsigned int idx;
        std::string line;
        std::queue<Token> tokens;
        void tokenize();


};

#endif // SCANNER_H
