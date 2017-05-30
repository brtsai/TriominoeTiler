//
// Created by Bryan Tsai on 30 May 2017
//

#include "PrintContext.h"

PrintContext::PrintContext (size_t newLineLength, std::string newDelimiters) {
    lineLength = newLineLength;
    delimiters = newDelimiters;
    counter = 0;
}

void PrintContext::printAsNext (std::ostream& ostream, char* c ) {
    if (counter != 0) ostream << delimiters;
    ostream << *c;
    if (lineLength != SIZE_MAX && ++counter >= lineLength) {
        ostream << std::endl;
        counter = 0;
    }
}

void PrintContext::printAsNext (char* c) {
    printAsNext (std::cout, c);
}

size_t PrintContext::getLineLength() {
    return lineLength;
}

std::string PrintContext::getDelimiters() {
    return delimiters;
}

std::ostream& operator<< (std::ostream& ostream, const PrintContext& pc) {
    ostream << "Details for Print Context [" << &pc << "]: lineLength: " 
    << pc.lineLength << " delimiters: \"" << pc.delimiters << "\"." << std::endl; 
    return ostream;
}
