//
// Created by Bryan Tsai on 26/05/2017
//

#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "PrintContext.h"

class Board {
private:
    std::vector<std::vector<char>> board;
    size_t dimension;
    void foldBoard(std::function<void(char *)>);
public:

    Board() = default;
    ~Board() = default;
    Board(size_t);

    void fillBoard(char);
    void printBoard();

};



#endif
