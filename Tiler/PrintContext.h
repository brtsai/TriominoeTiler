//
// Created by Bryan Tsai on 30 May 2017
//

#ifndef PRINTCONTEXT_H
#define PRINTCONTEXT_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

class PrintContext {
    private:
        size_t lineLength;
        size_t counter;
        std::string delimiters;

    public:
        PrintContext (size_t lineLength, std::string delimiters);

        void printAsNext (std::ostream&, char*);
        void printAsNext (char*);
        size_t getLineLength();
        std::string getDelimiters();
        friend std::ostream& operator<< (std::ostream&, const PrintContext&);
};

#endif
